/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "VerticalRms.h"

//==============================================================================
/**
*/
class RmsMeterAudioProcessorEditor  : public juce::AudioProcessorEditor , public Timer

{
public:
    RmsMeterAudioProcessorEditor (RmsMeterAudioProcessor&);
    ~RmsMeterAudioProcessorEditor() override;

    void timerCallback() override;
    //==============================================================================

    void paint (juce::Graphics&) override;
    void resized() override;

    Gui::VerticalMeter verticalMeterL, verticalMeterR; // verticals

private:
    
    RmsMeterAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RmsMeterAudioProcessorEditor)
};
