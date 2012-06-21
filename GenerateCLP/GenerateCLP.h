// This file was automatically generated by:
//  /home/jchris/Projects/Slicer4-Qt-PythonQt-With-Tcl-Debug/Slicer-build/bin/GenerateCLP --InputXML GenerateCLP.xml --OutputCxx GenerateCLP.h
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <sstream>

#include "tclap/CmdLine.h"
#include "ModuleProcessInformation.h"

#ifdef WIN32
#define Module_EXPORT __declspec(dllexport)
#else
#define Module_EXPORT 
#endif

#if defined(main) && !defined(REGISTER_TEST)
// If main defined as a preprocessor symbol, redefine it to the expected entry point.
#undef main
#define main ModuleEntryPoint

extern "C" {
  Module_EXPORT char *GetXMLModuleDescription();
  Module_EXPORT int ModuleEntryPoint(int, char*[]);
}
#endif

extern "C" {
Module_EXPORT char XMLModuleDescription[] = 
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
"<executable>\n"
"  <category>utility</category>\n"
"  <title>NAMIC Command Line Processing Code Generator</title>\n"
"  <description>Generates C++ code that will parse command lines</description>\n"
"  <version>1.0</version>\n"
"  <documentation-url></documentation-url>\n"
"  <license></license>\n"
"  <contributor>Bill Lorensen</contributor>\n"
"\n"
"  <parameters>\n"
"    <label>Parameters</label>\n"
"    <description>Parameters used for command line processing</description>\n"
"    <boolean>\n"
"      <name>UseTCLAP</name>\n"
"      <longflag>--TCLAP</longflag>\n"
"      <description>Generate TCLAP Code</description>\n"
"      <label>Generate TCLAP Code</label>\n"
"      <default>true</default>\n"
"    </boolean>\n"
"  </parameters>\n"
"  <parameters>\n"
"    <label>IO</label>\n"
"    <description>Input/Output parameters</description>\n"
"    <file multiple=\"true\">\n"
"      <name>logoFiles</name>\n"
"      <label>Logo Files XML</label>\n"
"      <longflag>--logoFiles</longflag>\n"
"      <description>Logo files</description>\n"
"    </file>\n"
"    <file>\n"
"      <name>InputXML</name>\n"
"      <label>Input XML</label>\n"
"      <channel>input</channel>\n"
"      <longflag>--InputXML</longflag>\n"
"      <description>XML description of interface</description>\n"
"    </file>\n"
"    <file>\n"
"      <name>OutputCxx</name>\n"
"      <label>Output C++</label>\n"
"      <channel>output</channel>\n"
"      <longflag>--OutputCxx</longflag>\n"
"      <description>C++ Code to process command line arguments</description>\n"
"    </file>\n"
"  </parameters>\n"
"</executable>\n"
"\n"
"\n"
;

}

void
splitString (const std::string &text,
             const std::string &separators,
             std::vector<std::string> &words)
{
  const std::string::size_type n = text.length();
  std::string::size_type start = text.find_first_not_of(separators);
  while (start < n)
    {
    std::string::size_type stop = text.find_first_of(separators, start);
    if (stop > n) stop = n;
    words.push_back(text.substr(start, stop - start));
    start = text.find_first_not_of(separators, stop+1);
    }
}

void
splitFilenames (const std::string &text,
                std::vector<std::string> &words)
{
  const std::string::size_type n = text.length();
  bool quoted;
  std::string comma(",");
  std::string quote("\"");
  std::string::size_type start = text.find_first_not_of(comma);
  while (start < n)
    {
    quoted = false;
    std::string::size_type startq = text.find_first_of(quote, start);
    std::string::size_type stopq = text.find_first_of(quote, startq+1);
    std::string::size_type stop = text.find_first_of(comma, start);
    if (stop > n) stop = n;
    if (startq != std::string::npos && stopq != std::string::npos)
      {
      while (startq < stop && stop < stopq && stop != n)
         {
         quoted = true;
         stop = text.find_first_of(comma, stop+1);
         if (stop > n) stop = n;
         }
      }
    if (!quoted)
      {
      words.push_back(text.substr(start, stop - start));
      }
    else
      {
      words.push_back(text.substr(start+1, stop - start-2));
      }
    start = text.find_first_not_of(comma, stop+1);
    }
}

char *GetXMLModuleDescription()
{
   return XMLModuleDescription;
}

#define GENERATE_LOGO
#define GENERATE_XML \
  if (argc >= 2 && (strcmp(argv[1],"--xml") == 0)) \
    { \
    std::cout << GetXMLModuleDescription(); \
    return EXIT_SUCCESS; \
    }
#define GENERATE_TCLAP \
    bool UseTCLAP = false; \
    std::vector<std::string> logoFilesTemp; \
    std::vector<std::string> logoFiles; \
    std::string InputXML; \
    std::string OutputCxx; \
    bool echoSwitch = false; \
    bool xmlSwitch = false; \
    std::string processInformationAddressString = "0"; \
    std::string returnParameterFile; \
    std::string fullDescription("Description: "); \
    fullDescription += "Generates C++ code that will parse command lines"; \
    if (!std::string("Bill Lorensen").empty()) \
      { \
      fullDescription += "\nAuthor(s): Bill Lorensen"; \
      } \
    if (!std::string("Thank you everyone.").empty()) \
      { \
      fullDescription += "\nAcknowledgements: Thank you everyone."; \
      } \
    TCLAP::CmdLine commandLine (fullDescription, \
       ' ', \
      "1.0" ); \
 \
      itksys_ios::ostringstream msg; \
    msg.str("");msg << "Generate TCLAP Code (default: " << UseTCLAP << ")"; \
    TCLAP::SwitchArg UseTCLAPArg("", "TCLAP", msg.str(), commandLine, UseTCLAP); \
 \
    msg.str("");msg << "Logo files";    TCLAP::MultiArg<std::string > logoFilesArg("", "logoFiles", msg.str(), 0, "std::vector<std::string>", commandLine); \
 \
    msg.str("");msg << "XML description of interface";    TCLAP::ValueArg<std::string > InputXMLArg("", "InputXML", msg.str(), 0, InputXML, "std::string", commandLine); \
 \
    msg.str("");msg << "C++ Code to process command line arguments";    TCLAP::ValueArg<std::string > OutputCxxArg("", "OutputCxx", msg.str(), 0, OutputCxx, "std::string", commandLine); \
 \
    msg.str("");msg << "Echo the command line arguments (default: " << echoSwitch << ")"; \
    TCLAP::SwitchArg echoSwitchArg("", "echo", msg.str(), commandLine, echoSwitch); \
 \
    msg.str("");msg << "Produce xml description of command line arguments (default: " << xmlSwitch << ")"; \
    TCLAP::SwitchArg xmlSwitchArg("", "xml", msg.str(), commandLine, xmlSwitch); \
 \
    msg.str("");msg << "Address of a structure to store process information (progress, abort, etc.). (default: " << processInformationAddressString << ")"; \
    TCLAP::ValueArg<std::string > processInformationAddressStringArg("", "processinformationaddress", msg.str(), 0, processInformationAddressString, "std::string", commandLine); \
 \
    msg.str("");msg << "Filename in which to write simple return parameters (int, float, int-vector, etc.) as opposed to bulk return parameters (image, geometry, transform, measurement, table).";    TCLAP::ValueArg<std::string > returnParameterFileArg("", "returnparameterfile", msg.str(), 0, returnParameterFile, "std::string", commandLine); \
 \
try \
  { \
    /* Build a map of flag aliases to the true flag */ \
    std::map<std::string,std::string> flagAliasMap; \
    std::map<std::string,std::string> deprecatedFlagAliasMap; \
    std::map<std::string,std::string> longFlagAliasMap; \
    std::map<std::string,std::string> deprecatedLongFlagAliasMap; \
    /* Remap flag aliases to the true flag */ \
    std::vector<std::string> targs; \
    std::map<std::string,std::string>::iterator ait; \
    std::map<std::string,std::string>::iterator dait; \
    size_t ac; \
    for (ac=0; ac < static_cast<size_t>(argc); ++ac)  \
       {  \
       if (strlen(argv[ac]) == 2 && argv[ac][0]=='-') \
         { \
         /* short flag case */ \
         std::string tflag(argv[ac], 1, strlen(argv[ac])-1); \
         ait = flagAliasMap.find(tflag); \
         dait = deprecatedFlagAliasMap.find(tflag); \
         if (ait != flagAliasMap.end() || dait != deprecatedFlagAliasMap.end()) \
           { \
           if (ait != flagAliasMap.end()) \
             { \
             /* remap the flag */ \
             targs.push_back("-" + (*ait).second); \
             } \
           else if (dait != deprecatedFlagAliasMap.end()) \
             { \
             std::cout << "Flag \"" << argv[ac] << "\" is deprecated. Please use flag \"-" << (*dait).second << "\" instead. " << std::endl; \
             /* remap the flag */ \
             targs.push_back("-" + (*dait).second); \
             } \
           } \
         else \
           { \
           targs.push_back(argv[ac]); \
           } \
         } \
       else if (strlen(argv[ac]) > 2 && argv[ac][0]=='-' && argv[ac][1]=='-') \
         { \
         /* long flag case */ \
         std::string tflag(argv[ac], 2, strlen(argv[ac])-2); \
         ait = longFlagAliasMap.find(tflag); \
         dait = deprecatedLongFlagAliasMap.find(tflag); \
         if (ait != longFlagAliasMap.end() || dait != deprecatedLongFlagAliasMap.end()) \
           { \
           if (ait != longFlagAliasMap.end()) \
             { \
             /* remap the flag */ \
             targs.push_back("--" + (*ait).second); \
             } \
           else if (dait != deprecatedLongFlagAliasMap.end()) \
             { \
             std::cout << "Long flag \"" << argv[ac] << "\" is deprecated. Please use long flag \"--" << (*dait).second << "\" instead. " << std::endl; \
             /* remap the flag */ \
             targs.push_back("--" + (*dait).second); \
             } \
           } \
         else \
           { \
           targs.push_back(argv[ac]); \
           } \
         } \
       else if (strlen(argv[ac]) > 2 && argv[ac][0]=='-' && argv[ac][1]!='-') \
         { \
         /* short flag case where multiple flags are given at once ala */ \
         /* "ls -ltr" */ \
         std::string tflag(argv[ac], 1, strlen(argv[ac])-1); \
         std::string rflag("-"); \
         for (std::string::size_type fi=0; fi < tflag.size(); ++fi) \
           { \
           std::string tf(tflag, fi, 1); \
           ait = flagAliasMap.find(tf); \
           dait = deprecatedFlagAliasMap.find(tf); \
           if (ait != flagAliasMap.end() || dait != deprecatedFlagAliasMap.end()) \
             { \
             if (ait != flagAliasMap.end()) \
               { \
               /* remap the flag */ \
               rflag += (*ait).second; \
               } \
             else if (dait != deprecatedFlagAliasMap.end()) \
               { \
               std::cout << "Flag \"-" << tf << "\" is deprecated. Please use flag \"-" << (*dait).second << "\" instead. " << std::endl; \
               /* remap the flag */ \
               rflag += (*dait).second; \
               } \
             } \
           else \
             { \
             rflag += tf; \
             } \
           } \
         targs.push_back(rflag); \
         } \
       else \
         { \
         /* skip the argument without remapping (this is the case for any */ \
         /* arguments for flags */ \
         targs.push_back(argv[ac]); \
         } \
       } \
 \
   /* Remap args to a structure that CmdLine::parse() can understand*/ \
   std::vector<char*> vargs; \
   for (ac = 0; ac < targs.size(); ++ac) \
     {  \
     vargs.push_back(const_cast<char *>(targs[ac].c_str())); \
     } \
    commandLine.parse ( vargs.size(), (char**) &(vargs[0]) ); \
    UseTCLAP = UseTCLAPArg.getValue(); \
    logoFilesTemp = logoFilesArg.getValue(); \
    InputXML = InputXMLArg.getValue(); \
    OutputCxx = OutputCxxArg.getValue(); \
    echoSwitch = echoSwitchArg.getValue(); \
    xmlSwitch = xmlSwitchArg.getValue(); \
    processInformationAddressString = processInformationAddressStringArg.getValue(); \
    returnParameterFile = returnParameterFileArg.getValue(); \
      { /* Assignment for logoFiles */ \
      for (unsigned int _i = 0; _i < logoFilesTemp.size(); _i++) \
        { \
        std::vector<std::string> words; \
        std::vector<std::string> elements; \
        words.clear(); \
        splitFilenames(logoFilesTemp[_i], words); \
        for (unsigned int _j= 0; _j < words.size(); _j++) \
          { \
            logoFiles.push_back((words[_j].c_str())); \
          } \
        } \
      } \
  } \
catch ( TCLAP::ArgException e ) \
  { \
  std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; \
  return ( EXIT_FAILURE ); \
  }
#define GENERATE_ECHOARGS \
if (echoSwitch) \
{ \
std::cout << "Command Line Arguments" << std::endl; \
std::cout << "    UseTCLAP: " << UseTCLAP << std::endl; \
for (unsigned int _i= 0; _i < logoFilesTemp.size(); _i++) \
{ \
std::cout << "logoFiles[" << _i << "]: "; \
std::vector<std::string> words; \
words.clear(); \
splitFilenames(logoFilesTemp[_i], words); \
for (unsigned int _j= 0; _j < words.size(); _j++) \
{ \
std::cout <<  words[_j] << " "; \
} \
std::cout << std::endl; \
} \
std::cout << "    InputXML: " << InputXML << std::endl; \
std::cout << "    OutputCxx: " << OutputCxx << std::endl; \
std::cout << "    echoSwitch: " << echoSwitch << std::endl; \
std::cout << "    xmlSwitch: " << xmlSwitch << std::endl; \
std::cout << "    processInformationAddressString: " << processInformationAddressString << std::endl; \
std::cout << "    returnParameterFile: " << returnParameterFile << std::endl; \
}
#define GENERATE_ProcessInformationAddressDecoding \
ModuleProcessInformation *CLPProcessInformation = 0; \
if (processInformationAddressString != "") \
{ \
sscanf(processInformationAddressString.c_str(), "%p", &CLPProcessInformation); \
}
#define PARSE_ARGS GENERATE_LOGO;GENERATE_XML;GENERATE_TCLAP;GENERATE_ECHOARGS;GENERATE_ProcessInformationAddressDecoding;
