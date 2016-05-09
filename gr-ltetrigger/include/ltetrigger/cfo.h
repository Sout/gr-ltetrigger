/* -*- c++ -*- */
/*
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_LTETRIGGER_CFO_H
#define INCLUDED_LTETRIGGER_CFO_H

#include <ltetrigger/api.h>
#include <gnuradio/sync_block.h>

#include <srslte/srslte.h>


namespace gr {
  namespace ltetrigger {

    /*!
     * \brief perform carrier frequency offset correction
     * \ingroup ltetrigger
     *
     */
    class LTETRIGGER_API cfo : virtual public gr::sync_block
    {
    public:
      typedef boost::shared_ptr<cfo> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of ltetrigger::cfo.
       *
       * To avoid accidental use of raw pointers, ltetrigger::cfo's
       * constructor is in a private implementation
       * class. ltetrigger::cfo::make is the public interface for
       * creating new instances.
       */
      static sptr make();

      /*! \brief Set carrier frequency
       *
       * If fc not set, carrier frequency offset correction is disabled and
       * this is a pass-through block. Setting fc enables (or re-enables) this
       * block.
       */
      virtual void set_fc(float fc) = 0;

      /*! \brief Return current center frequency
       *
       * If block is disabled or fc is not set, return value is undefined.
       */
      virtual float fc() = 0;

      /*! \brief Disable carrier frequency offset correction */
      virtual void disable() = 0;

      /*! \brief Return true if CFO correction is enabled, else false */
      virtual bool is_enabled() = 0;
    };

  } // namespace ltetrigger
} // namespace gr

#endif /* INCLUDED_LTETRIGGER_CFO_H */
