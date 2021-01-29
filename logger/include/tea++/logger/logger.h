//
// Created by lsc on 21-01-29.
//

//#ifndef TEACC_LOGGER_H
//#define TEACC_LOGGER_H

// Code template modified by oldlonesomecoder.
#pragma once

#include <tea++/utils/colors.h>


namespace teacc
{

class logger
{

public:
    enum class output_types :uint8_t
    {
        type_ansi,
        type_html,
        type_plain
    };
    
    logger();
    
};

}
//#endif //TEACC_LOGGER_H
