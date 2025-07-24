#if defined(__ROOTCLING__)

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ struct dataProducts::NaluPacketHeader+;
#pragma link C++ struct dataProducts::NaluPacketFooter+;
#pragma link C++ struct dataProducts::NaluPacketPayload;
#pragma link C++ struct dataProducts::NaluEventHeader+;
#pragma link C++ class dataProducts::NaluPacket+;
#pragma link C++ class dataProducts::NaluPacketCollection+;
#pragma link C++ struct dataProducts::NaluEventFooter+;
#pragma link C++ class dataProducts::NaluEvent+;
#pragma link C++ struct dataProducts::NaluTime+;
#pragma link C++ class dataProducts::NaluWaveform+;
#pragma link C++ class dataProducts::NaluWaveformCollection+;

#endif
