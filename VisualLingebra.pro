TEMPLATE = subdirs

SUBDIRS += \
    VisualLingebra \
    vlutils

VisualLingebra.subdir = src/VisualLingebra
vlutils.subdir = src/vlutils

VisualLingebra.depends = vlutils
