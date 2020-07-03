TEMPLATE = subdirs

SUBDIRS += library test_app

test_app.depends = library
