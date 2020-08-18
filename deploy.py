#!/usr/bin/env python3
import argparse
import os
from pathlib import Path

parser = argparse.ArgumentParser(description=
    'Deploy boilerplate code for a library and corresponding test app '
    'with a new name.')

parser.add_argument('libraryName', type=str, help=
    'New name used for new topdir, filenames and content substitutions.')

parser.add_argument('--debug', action="store_true", help=
    'No change written to filesystem, just printing out what would be created.')

args = parser.parse_args()

libraryName = args.libraryName
# decapitalize
libraryName = libraryName[0].lower() + libraryName[1:]
# capitalize (builtin capitalize mess with rest, e.g. camelCase -> Camelcase :-/)
LibraryName = libraryName[0].upper() + libraryName[1:]

forbidden_chars = '.,:/'
if any(c in libraryName for c in forbidden_chars):
    print(f'No forbiddem chars, i.e. {forbidden_chars}, in libraryName.'
           'Exiting...')
    exit()

original_topdir = Path(__file__).parents[0]
# print(original_topdir)

new_topdir = Path.cwd() / libraryName / "src"
# print(new_topdir)

# Dictionary of stuff to be deployed. Keys are original file paths relative
# to original_topdir, values are tuples:
#
#     (new path relative to new_topdir, Substitution tuples list)
#
# Substitution tuples list is simply a list of (old_str, new_str}.
#
files2substitutions = {
    "boilerplate.pro": (
        libraryName + '.pro',
        [('library', libraryName)]
    ),
    ".gitignore": (
        ".gitignore",
        []
    ),
    "library/exampleLibrary.cpp": (
        libraryName + '/' + libraryName + '.cpp',
        [('exampleLibrary.h', libraryName + '.h'),
         ('ExampleLibrary', LibraryName)]
    ),
    "library/exampleLibrary.h": (
        libraryName + '/' + libraryName + '.h',
        [('EXAMPLELIBRARY_H', libraryName.upper() + '_H'),
         ('ExampleLibrary', LibraryName)]
    ),
    "library/library.pro": (
        libraryName + '/' + libraryName + '.pro',
        [('exampleLibrary', libraryName)]
    ),
    "test_app/main.cpp": (
        "test_app/main.cpp",
        []
    ),
    "test_app/mainwindow.cpp": (
        "test_app/mainwindow.cpp",
        [('ExampleLibrary', LibraryName)]
    ),
    "test_app/mainwindow.h": (
        "test_app/mainwindow.h",
        [('exampleLibrary', libraryName),
         ('ExampleLibrary', LibraryName)]
    ),
    "test_app/mainwindow.ui":  (
        "test_app/mainwindow.ui",
        [("Example application", f"{LibraryName} test application")]
    ),
    "test_app/test_app.pro": (
        "test_app/test_app.pro",
        [("library", libraryName)]
    ),
}

for original in files2substitutions:
    new, substitutions = files2substitutions[original]
    old = original_topdir / original
    new = new_topdir / new
    
    with open(old) as f:
        content = f.read()
    for s in substitutions:
        content = content.replace(s[0], s[1])

    if args.debug:
        print(new)
        print(80*"=")
        print(content)
        print(100 * "=" + "\n" + 100 * "=")
    else:
        new.parents[0].mkdir(parents=True, exist_ok=True)

        with open(new, "w") as f:
            f.write(content)



