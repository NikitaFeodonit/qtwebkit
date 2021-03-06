/*
 * This file is part of the WebKit open source project.
 * This file has been generated by generate-bindings.pl. DO NOT MODIFY!
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "config.h"

#if ENABLE(Condition1) || ENABLE(Condition2)

#include "WebDOMTestInterface.h"

#include "KURL.h"
#include "Node.h"
#include "TestInterface.h"
#include "TestSupplemental.h"
#include "WebDOMNode.h"
#include "WebDOMString.h"
#include "WebExceptionHandler.h"
#include <wtf/GetPtr.h>
#include <wtf/RefPtr.h>
#include <wtf/text/AtomicString.h>

struct WebDOMTestInterface::WebDOMTestInterfacePrivate {
    WebDOMTestInterfacePrivate(WebCore::TestInterface* object = 0)
        : impl(object)
    {
    }

    RefPtr<WebCore::TestInterface> impl;
};

WebDOMTestInterface::WebDOMTestInterface()
    : WebDOMObject()
    , m_impl(0)
{
}

WebDOMTestInterface::WebDOMTestInterface(WebCore::TestInterface* impl)
    : WebDOMObject()
    , m_impl(new WebDOMTestInterfacePrivate(impl))
{
}

WebDOMTestInterface::WebDOMTestInterface(const WebDOMTestInterface& copy)
    : WebDOMObject()
{
    m_impl = copy.impl() ? new WebDOMTestInterfacePrivate(copy.impl()) : 0;
}

WebDOMTestInterface& WebDOMTestInterface::operator=(const WebDOMTestInterface& copy)
{
    delete m_impl;
    m_impl = copy.impl() ? new WebDOMTestInterfacePrivate(copy.impl()) : 0;
    return *this;
}

WebCore::TestInterface* WebDOMTestInterface::impl() const
{
    return m_impl ? WTF::getPtr(m_impl->impl) : 0;
}

WebDOMTestInterface::~WebDOMTestInterface()
{
    delete m_impl;
    m_impl = 0;
}

#if ENABLE(Condition22) || ENABLE(Condition23)
WebDOMString WebDOMTestInterface::implementsStr1() const
{
    if (!impl())
        return WebDOMString();

    return static_cast<const WTF::String&>(impl()->implementsStr1());
}

#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
WebDOMString WebDOMTestInterface::implementsStr2() const
{
    if (!impl())
        return WebDOMString();

    return static_cast<const WTF::String&>(impl()->implementsStr2());
}

void WebDOMTestInterface::setImplementsStr2(const WebDOMString& newImplementsStr2)
{
    if (!impl())
        return;

    impl()->setImplementsStr2(newImplementsStr2);
}

#endif
#if ENABLE(Condition22) || ENABLE(Condition23)
WebDOMNode WebDOMTestInterface::implementsNode() const
{
    if (!impl())
        return WebDOMNode();

    return toWebKit(WTF::getPtr(impl()->implementsNode()));
}

void WebDOMTestInterface::setImplementsNode(const WebDOMNode& newImplementsNode)
{
    if (!impl())
        return;

    impl()->setImplementsNode(toWebCore(newImplementsNode));
}

#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
WebDOMString WebDOMTestInterface::supplementalStr1() const
{
    if (!impl())
        return WebDOMString();

    return static_cast<const WTF::String&>(TestSupplemental::supplementalStr1(impl()));
}

#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
WebDOMString WebDOMTestInterface::supplementalStr2() const
{
    if (!impl())
        return WebDOMString();

    return static_cast<const WTF::String&>(TestSupplemental::supplementalStr2(impl()));
}

void WebDOMTestInterface::setSupplementalStr2(const WebDOMString& newSupplementalStr2)
{
    if (!impl())
        return;

    TestSupplemental::setSupplementalStr2(impl(), newSupplementalStr2);
}

#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
WebDOMNode WebDOMTestInterface::supplementalNode() const
{
    if (!impl())
        return WebDOMNode();

    return toWebKit(WTF::getPtr(TestSupplemental::supplementalNode(impl())));
}

void WebDOMTestInterface::setSupplementalNode(const WebDOMNode& newSupplementalNode)
{
    if (!impl())
        return;

    TestSupplemental::setSupplementalNode(impl(), toWebCore(newSupplementalNode));
}

#endif

#if ENABLE(Condition22) || ENABLE(Condition23)
void WebDOMTestInterface::implementsMethod1()
{
    if (!impl())
        return;

    impl()->implementsMethod1();
}

#endif


#if ENABLE(Condition22) || ENABLE(Condition23)
void WebDOMTestInterface::implementsMethod4()
{
    if (!impl())
        return;

    impl()->implementsMethod4();
}

#endif


#if ENABLE(Condition11) || ENABLE(Condition12)
void WebDOMTestInterface::supplementalMethod1()
{
    if (!impl())
        return;

    WebCore::TestSupplemental::supplementalMethod1(impl());
}

#endif


#if ENABLE(Condition11) || ENABLE(Condition12)
void WebDOMTestInterface::supplementalMethod4()
{
    if (!impl())
        return;

    WebCore::TestSupplemental::supplementalMethod4(impl());
}

#endif

WebCore::TestInterface* toWebCore(const WebDOMTestInterface& wrapper)
{
    return wrapper.impl();
}

WebDOMTestInterface toWebKit(WebCore::TestInterface* value)
{
    return WebDOMTestInterface(value);
}

#endif // ENABLE(Condition1) || ENABLE(Condition2)
