// __BEGIN_LICENSE__
//  Copyright (c) 2006-2012, United States Government as represented by the
//  Administrator of the National Aeronautics and Space Administration. All
//  rights reserved.
//
//  The NASA Vision Workbench is licensed under the Apache License,
//  Version 2.0 (the "License"); you may not use this file except in
//  compliance with the License. You may obtain a copy of the License at
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
// __END_LICENSE__


#ifndef __VW_FILEIO_MEMORYIMAGERESOURCEJPEG_H__
#define __VW_FILEIO_MEMORYIMAGERESOURCEJPEG_H__

#include <vw/FileIO/MemoryImageResource.h>
#include <boost/noncopyable.hpp>

namespace vw {

  class SrcMemoryImageResourceJPEG : public SrcMemoryImageResource, private boost::noncopyable {
      class Data;
      mutable boost::shared_ptr<Data> m_data;

    public:
      SrcMemoryImageResourceJPEG(boost::shared_array<const uint8> buffer, size_t len);

      virtual void read( ImageBuffer const& buf, BBox2i const& bbox ) const;

      virtual ImageFormat format() const;

      virtual bool has_block_read() const  {return false;}
      virtual bool has_nodata_read() const {return false;}
  };

  class DstMemoryImageResourceJPEG : public DstMemoryImageResource {
      class Data;
      boost::shared_ptr<Data> m_data;

    public:
      DstMemoryImageResourceJPEG(const ImageFormat& fmt);

      virtual void write( ImageBuffer const& buf, BBox2i const& bbox );
      virtual void flush() {}

      virtual bool has_block_write()  const {return false;}
      virtual bool has_nodata_write() const {return false;}

      virtual const uint8* data() const;
      virtual size_t size() const;
  };

}

#endif
