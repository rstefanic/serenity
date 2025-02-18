/*
 * Copyright (c) 2021, Andreas Kling <kling@serenityos.org>
 * Copyright (c) 2022, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Error.h>
#include <AK/Span.h>
#include <AK/StringView.h>

namespace Main {

struct Arguments {
    int argc {};
    char** argv {};
    Span<StringView> strings;
};

}

ErrorOr<int> serenity_main(Main::Arguments);
