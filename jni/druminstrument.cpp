/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2014 Igor Zinken - http://www.igorski.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include "druminstrument.h"
#include "audioengine.h"
#include "sequencer.h"
#include "utils.h"
#include <cstddef>

/* constructor / destructor */

DrumInstrument::DrumInstrument()
{
    rOsc = 0;//rOsc            = new RouteableOscillator();  // currently unused...
    processingChain = new ProcessingChain();
    audioChannel    = new AudioChannel( processingChain, this->volume, AudioEngine::bytes_per_bar );

    volume    = .5;
    drumTimbre = DrumSynthTimbres::LIGHT;

    sequencer::drummachine = this;  // register instrument inside the sequencer
}

DrumInstrument::~DrumInstrument()
{
    DebugTool::log( "DrumInstrument::DESTRUCT" );

    sequencer::drummachine = 0;

    delete rOsc;
    delete audioChannel;
    delete processingChain;
}