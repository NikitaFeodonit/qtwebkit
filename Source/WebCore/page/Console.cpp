/*
 * Copyright (C) 2007 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "Console.h"

#include "Chrome.h"
#include "ChromeClient.h"

#if ENABLE(CFG_INSPECTOR)
#include "ConsoleAPITypes.h"
#endif

#include "ConsoleTypes.h"
#include "Document.h"
#include "Frame.h"
#include "FrameLoader.h"
#include "FrameTree.h"

#if ENABLE(CFG_INSPECTOR)
#include "InspectorConsoleInstrumentation.h"
#include "InspectorController.h"
#endif

#include "Page.h"
#include "PageConsole.h"
#include "PageGroup.h"

#if ENABLE(CFG_INSPECTOR)
#include "ScriptArguments.h"
#include "ScriptCallStack.h"
#endif

#include "ScriptCallStackFactory.h"
#include "ScriptProfile.h"
#include "ScriptProfiler.h"
#include "ScriptValue.h"
#include "ScriptableDocumentParser.h"
#include "Settings.h"
#include <stdio.h>
#include <wtf/text/CString.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

Console::Console(Frame* frame)
    : DOMWindowProperty(frame)
{
}

Console::~Console()
{
}

#if ENABLE(CFG_INSPECTOR)
static void internalAddMessage(Page* page, MessageType type, MessageLevel level, ScriptState* state, PassRefPtr<ScriptArguments> prpArguments, bool acceptNoArguments = false, bool printTrace = false)
{
    RefPtr<ScriptArguments> arguments = prpArguments;

    if (!page)
        return;

    if (!acceptNoArguments && !arguments->argumentCount())
        return;

    size_t stackSize = printTrace ? ScriptCallStack::maxCallStackSizeToCapture : 1;
    RefPtr<ScriptCallStack> callStack(createScriptCallStack(state, stackSize));
    const ScriptCallFrame& lastCaller = callStack->at(0);

    String message;
    bool gotMessage = arguments->getFirstArgumentAsString(message);
    InspectorInstrumentation::addMessageToConsole(page, ConsoleAPIMessageSource, type, level, message, state, arguments);

    if (page->settings()->privateBrowsingEnabled())
        return;

    if (gotMessage)
        page->chrome().client()->addMessageToConsole(ConsoleAPIMessageSource, type, level, message, lastCaller.lineNumber(), lastCaller.columnNumber(), lastCaller.sourceURL());

    if (!page->settings()->logsPageMessagesToSystemConsoleEnabled() && !PageConsole::shouldPrintExceptions())
        return;

    PageConsole::printSourceURLAndLine(lastCaller.sourceURL(), lastCaller.lineNumber());
    PageConsole::printMessageSourceAndLevelPrefix(ConsoleAPIMessageSource, level);

    for (size_t i = 0; i < arguments->argumentCount(); ++i) {
        String argAsString = arguments->argumentAt(i).toString(arguments->globalState());
        printf(" %s", argAsString.utf8().data());
    }

    printf("\n");

    if (printTrace) {
        printf("Stack Trace\n");
        for (size_t i = 0; i < callStack->size(); ++i) {
            String functionName = String(callStack->at(i).functionName());
            printf("\t%s\n", functionName.utf8().data());
        }
    }
}
#endif

void Console::debug(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    internalAddMessage(page(), LogMessageType, DebugMessageLevel, state, arguments);
#endif
}

void Console::error(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    internalAddMessage(page(), LogMessageType, ErrorMessageLevel, state, arguments);
#endif
}

void Console::info(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    log(state, arguments);
#endif
}

void Console::log(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    internalAddMessage(page(), LogMessageType, LogMessageLevel, state, arguments);
#endif
}

void Console::warn(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    internalAddMessage(page(), LogMessageType, WarningMessageLevel, state, arguments);
#endif
}

void Console::dir(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    internalAddMessage(page(), DirMessageType, LogMessageLevel, state, arguments);
#endif
}

void Console::dirxml(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    internalAddMessage(page(), DirXMLMessageType, LogMessageLevel, state, arguments);
#endif
}

void Console::table(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    internalAddMessage(page(), TableMessageType, LogMessageLevel, state, arguments);
#endif
}

void Console::clear(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    internalAddMessage(page(), ClearMessageType, LogMessageLevel, state, arguments, true);
#endif
}

void Console::trace(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    internalAddMessage(page(), TraceMessageType, LogMessageLevel, state, arguments, true, true);
#endif
}

void Console::assertCondition(ScriptState* state, PassRefPtr<ScriptArguments> arguments, bool condition)
{
    if (condition)
        return;

#if ENABLE(CFG_INSPECTOR)
    internalAddMessage(page(), AssertMessageType, ErrorMessageLevel, state, arguments, true);
#endif
}

void Console::count(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    InspectorInstrumentation::consoleCount(page(), state, arguments);
#endif
}

#if ENABLE(JAVASCRIPT_DEBUGGER)

void Console::profile(const String& title, ScriptState* state)
{
    Page* page = this->page();
    if (!page)
        return;

    // FIXME: log a console message when profiling is disabled.
#if ENABLE(CFG_INSPECTOR)
    if (!InspectorInstrumentation::profilerEnabled(page))
#endif
        return;

    String resolvedTitle = title;
#if ENABLE(CFG_INSPECTOR)
    if (title.isNull()) // no title so give it the next user initiated profile title.
        resolvedTitle = InspectorInstrumentation::getCurrentUserInitiatedProfileName(page, true);
#endif

    ScriptProfiler::start(state, resolvedTitle);

#if ENABLE(CFG_INSPECTOR)
    RefPtr<ScriptCallStack> callStack(createScriptCallStack(state, 1));
    const ScriptCallFrame& lastCaller = callStack->at(0);
    InspectorInstrumentation::addStartProfilingMessageToConsole(page, resolvedTitle, lastCaller.lineNumber(), lastCaller.columnNumber(), lastCaller.sourceURL());
#endif
}

void Console::profileEnd(const String& title, ScriptState* state)
{
    Page* page = this->page();
    if (!page)
        return;

#if ENABLE(CFG_INSPECTOR)
    if (!InspectorInstrumentation::profilerEnabled(page))
#endif
        return;

    RefPtr<ScriptProfile> profile = ScriptProfiler::stop(state, title);
    if (!profile)
        return;

    m_profiles.append(profile);
#if ENABLE(CFG_INSPECTOR)
    RefPtr<ScriptCallStack> callStack(createScriptCallStack(state, 1));
    InspectorInstrumentation::addProfile(page, profile, callStack);
#endif
}

#endif

void Console::time(const String& title)
{
#if ENABLE(CFG_INSPECTOR)
    InspectorInstrumentation::startConsoleTiming(m_frame, title);
#endif
}

void Console::timeEnd(ScriptState* state, const String& title)
{
#if ENABLE(CFG_INSPECTOR)
    RefPtr<ScriptCallStack> callStack(createScriptCallStackForConsole(state));
    InspectorInstrumentation::stopConsoleTiming(m_frame, title, callStack.release());
#endif
}

void Console::timeStamp(PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    InspectorInstrumentation::consoleTimeStamp(m_frame, arguments);
#endif
}

void Console::group(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    InspectorInstrumentation::addMessageToConsole(page(), ConsoleAPIMessageSource, StartGroupMessageType, LogMessageLevel, String(), state, arguments);
#endif
}

void Console::groupCollapsed(ScriptState* state, PassRefPtr<ScriptArguments> arguments)
{
#if ENABLE(CFG_INSPECTOR)
    InspectorInstrumentation::addMessageToConsole(page(), ConsoleAPIMessageSource, StartGroupCollapsedMessageType, LogMessageLevel, String(), state, arguments);
#endif
}

void Console::groupEnd()
{
#if ENABLE(CFG_INSPECTOR)
    InspectorInstrumentation::addMessageToConsole(page(), ConsoleAPIMessageSource, EndGroupMessageType, LogMessageLevel, String(), String(), 0, 0);
#endif
}

Page* Console::page() const
{
    if (!m_frame)
        return 0;
    return m_frame->page();
}

} // namespace WebCore
