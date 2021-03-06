/*This file is prepared for Doxygen automatic documentation generation.*/
/*! \file *********************************************************************
 *
 * \brief HALL ESTIMATOR for AVR32 UC3.
 *
 * AVR32 HALL ESTIMATOR module.
 *
 * - Compiler:           IAR EWAVR32 and GNU GCC for AVR32
 * - Supported devices:  All AVR32 devices with a TC module can be used.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.no/
 *
 ******************************************************************************/

/* Copyright (C) 2006-2008, Atmel Corporation All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. The name of ATMEL may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY AND
 * SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef _HALL_ESTIMATOR_H_
#define _HALL_ESTIMATOR_H_

#include <avr32/io.h>
#include "mc_driver.h"

//! Input parameters.
typedef struct
{

  //! Teta value in degree [0;60]
  U16 teta;
  
  //! Speed Value
  U32 speed;

  //! Sector number [1-2-3-4-5-6]
  U16 sector_number;
  
} hall_estimator_options_t;

//------------------------------------------------------------------------------
/*! \name Initialization Functions
 */
//! @{
/*! \brief Init HALL ESTIMATOR
 * \param *hall_estimator_options HALL_ESTIMATOR service options.
 * \retval NONE
 */
extern void hall_estimator_init(volatile hall_estimator_options_t *hall_estimator_options);
/*! \brief Start HALL ESTIMATOR service
 * \param *hall_estimator_options HALL_ESTIMATOR service options.
 * \retval NONE
 */
extern void hall_estimator_start(volatile hall_estimator_options_t *hall_estimator_options);
/*! \brief Init interrupt for HALL ESTIMATOR service
 * \param *hall_estimator_options HALL_ESTIMATOR service options.
 * \retval NONE
 */
extern void hall_estimator_init_interrupt(volatile hall_estimator_options_t *hall_estimator_options);
/*! \brief Do interrupt Request for HALL ESTIMATOR service
 */
extern void hall_estimator_do_interrupt(void);
//------------------------------------------------------------------------------
/*! \name Set/Get Functions
 */
//! @{
/*! \brief Update teta position/sector number value for HALL ESTIMATOR service
 * \param *hall_estimator_options HALL_ESTIMATOR service options.
 * \param resolution resolution to update value.
 * \retval NONE
 */
extern void hall_estimator_update_teta(volatile hall_estimator_options_t *hall_estimator_options,  U32 resolution);
/*! \brief Update speed value for HALL ESTIMATOR service
 * \param *hall_estimator_options HALL_ESTIMATOR service options.
 * \retval NONE
 */
extern void hall_estimator_update_speed(volatile hall_estimator_options_t *hall_estimator_options);

#endif  // _HALL_ESTIMATOR_H_
//@}
