/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef INCLUDED_DAB_OFDM_COARSE_FREQUENCY_CORRECT_IMPL_H
#define INCLUDED_DAB_OFDM_COARSE_FREQUENCY_CORRECT_IMPL_H

#include <dab/ofdm_coarse_frequency_correct.h>

namespace gr {
  namespace dab {

class ofdm_coarse_frequency_correct_impl : public ofdm_coarse_frequency_correct
{
  private:

    float mag_squared(const gr_complex sample);
    void correlate_energy(const gr_complex *symbol);

    unsigned int d_fft_length;
    unsigned int d_num_carriers;
    unsigned int d_cp_length;
    unsigned int d_symbol_num;
    unsigned int d_zeros_on_left;
    unsigned int d_freq_offset;
    int          d_delta_f;

  public:
   ofdm_coarse_frequency_correct_impl(unsigned int fft_length, unsigned int num_carriers, unsigned int cp_length);
    int work (int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items);
};

}
}

#endif /* INCLUDED_DAB_OFDM_COARSE_FREQUENCY_CORRECT_H */
