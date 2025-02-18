/*
 * Copyright (c) 2020, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/HTML/HTMLPictureElement.h>

namespace Web::HTML {

HTMLPictureElement::HTMLPictureElement(DOM::Document& document, DOM::QualifiedName qualified_name)
    : HTMLElement(document, move(qualified_name))
{
}

HTMLPictureElement::~HTMLPictureElement()
{
}

}
