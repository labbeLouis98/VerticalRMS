/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RmsMeterAudioProcessorEditor::RmsMeterAudioProcessorEditor (RmsMeterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (220, 400);

    addAndMakeVisible(verticalMeterL); // make visible the meters
    addAndMakeVisible(verticalMeterR);

    startTimerHz(30);
}

RmsMeterAudioProcessorEditor::~RmsMeterAudioProcessorEditor()
{
}


void RmsMeterAudioProcessorEditor::timerCallback()
{
    verticalMeterL.setLevel(audioProcessor.getRmsValue(0)); //fetch rms value sur chaques channels L et R
    verticalMeterR.setLevel(audioProcessor.getRmsValue(1));

    verticalMeterL.repaint();
    verticalMeterR.repaint();
}

//==============================================================================
void RmsMeterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colours::black);

   
    
}

void RmsMeterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..


    verticalMeterL.setBounds(100, 100,  15 , 200);
    verticalMeterR.setBounds(120, 100, 15, 200);
}
