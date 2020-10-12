TEMPLATE = subdirs

SUBDIRS += library test_app tests

test_app.depends = library
tests.depends = library

