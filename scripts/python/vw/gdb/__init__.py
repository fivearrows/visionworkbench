#!/usr/bin/env python

from __future__ import absolute_import

import gdb
import re
import sys

from vw.gdb import types

try:
    if not hasattr(sys, 'argv'):
        sys.argv = ['gdb']
    from IPython.Shell import IPShellEmbed
    _ipshell = IPShellEmbed(argv=[''],banner="Hello!",exit_msg="Goodbye!")
except ImportError:
    def noop():
        pass
    _ipshell = noop


pretty_printers_dict = None

def register_handler(types):
    for t in types:
        pretty_printers_dict[re.compile(t.PATTERN)] = t

def build_dictionary():
    global pretty_printers_dict
    pretty_printers_dict = {}
    register_handler([getattr(types, i) for i in dir(types) if i[0] != '_' and i[0] == i[0].upper()])

def lookup(val):
    "Look-up and return a pretty-printer that can print val."

    if pretty_printers_dict is None:
        build_dictionary()

    # Get the type.
    typ = val.type

    # If it points to a reference, get the reference.
    if typ.code == gdb.TYPE_CODE_REF:
        typ = typ.target()

    # Get the unqualified type, stripped of typedefs.
    typ = typ.unqualified().strip_typedefs()

    # Get the type name.
    typename = typ.tag
    if typename == None:
        return None

    # Iterate over local dictionary of types to determine
    # if a printer is registered for that type.  Return an
    # instantiation of the printer if found.
    for function in pretty_printers_dict:
        m = function.search(typename)
        if m:
            handler = pretty_printers_dict[function]
            if hasattr(handler, 'can_use'):
                if not handler.can_use(val):
                    return None
            return handler(typename, val)

    # Cannot find a pretty printer.  Return None.
    return None

def register(obj):
    "Register pretty-printers with objfile obj."
    if obj == None:
        obj = gdb
    obj.pretty_printers.append(lookup)

__all__ = (register)