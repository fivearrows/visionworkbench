# __BEGIN_LICENSE__
#  Copyright (c) 2006-2012, United States Government as represented by the
#  Administrator of the National Aeronautics and Space Administration. All
#  rights reserved.
#
#  The NASA Vision Workbench is licensed under the Apache License,
#  Version 2.0 (the "License"); you may not use this file except in
#  compliance with the License. You may obtain a copy of the License at
#  http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
# __END_LICENSE__


########################################################################
# sources
########################################################################

if MAKE_MODULE_HDR

include_HEADERS = CameraCurve.h GlobalToneMap.h LDRtoHDR.h	\
	LocalToneMap.h

libvwHDR_la_SOURCES = LocalToneMap.cc CameraCurve.cc

libvwHDR_la_LIBADD = @MODULE_HDR_LIBS@

lib_LTLIBRARIES = libvwHDR.la

endif

########################################################################
# general
########################################################################

AM_CPPFLAGS = @VW_CPPFLAGS@
AM_LDFLAGS = @VW_LDFLAGS@ $(LIBTOOL_LIB_FLAGS)

SUBDIRS = . tests

includedir = $(prefix)/include/vw/HDR

include $(top_srcdir)/config/rules.mak

