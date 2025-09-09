#if defined(__ROOTCLING__)

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ struct dataProducts::NaluEventHeader+;
#pragma link C++ struct dataProducts::NaluPacket+;
#pragma link C++ struct dataProducts::NaluEventFooter+;
#pragma link C++ class dataProducts::NaluPacketCollection+;
#pragma link C++ class dataProducts::NaluWaveform+;
#pragma link C++ class dataProducts::NaluWaveformCollection+;
#pragma link C++ class dataProducts::NaluEvent+;

#pragma link C++ struct dataProducts::NaluTimeData+;
#pragma link C++ class dataProducts::NaluTime+;

// STL containers
#pragma link C++ class std::vector<short>+;
#pragma link C++ class std::vector<dataProducts::NaluWaveform>+;
#pragma link C++ class std::vector<dataProducts::NaluPacket>+;

#endif
