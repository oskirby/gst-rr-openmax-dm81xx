/* 
 * GStreamer
 * Copyright (C) 2006 Stefan Kost <ensonic@users.sf.net>
 * Copyright (C) 2013 Michael Gruner <michael.gruner@ridgerun.com>
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
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GST_OMX_SCALER_H__
#define __GST_OMX_SCALER_H__

#include "gstomxbase.h"
#include "gstomxdeiscaler.h"

G_BEGIN_DECLS
#define GST_TYPE_OMX_SCALER \
  (gst_omx_scaler_get_type())
#define GST_OMX_SCALER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_OMX_SCALER,GstOmxScaler))
#define GST_OMX_SCALER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_OMX_SCALER,GstOmxScalerClass))
#define GST_IS_OMX_SCALER(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_OMX_SCALER))
#define GST_IS_OMX_SCALER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_OMX_SCALER))
typedef struct _GstOmxScaler GstOmxScaler;
typedef struct _GstOmxScalerClass GstOmxScalerClass;

struct _GstOmxScaler
{
  GstOmxBase base;

  GstPad *srcpad, *sinkpad;
  GstOmxFormat in_format;
  GstOmxFormat out_format;

  /* Properties */
  gchar *crop_str;
  GstCropArea crop_area;
};

struct _GstOmxScalerClass
{
  GstOmxBaseClass parent_class;
};

GType gst_omx_scaler_get_type (void);

G_END_DECLS
#endif /* __GST_OMX_SCALER_H__ */
