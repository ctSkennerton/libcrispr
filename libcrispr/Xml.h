// File: XML.h
// Original Author: Michael Imelfort 2011
// Extended: Connor Skennerton 2011, 2012
// --------------------------------------------------------------------
//
// OVERVIEW:
// 
// Defines The xml base, reader and writer classes
//
// Many thanks to http://www.yolinux.com/TUTORIALS/XML-Xerces-C.html
//
// --------------------------------------------------------------------
//  Copyright  2011 Michael Imelfort and Connor Skennerton
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see 'http://www.gnu.org/licenses/'.
// --------------------------------------------------------------------
//
//                        A
//                       A B
//                      A B R
//                     A B R A
//                    A B R A C
//                   A B R A C A
//                  A B R A C A D
//                 A B R A C A D A
//                A B R A C A D A B 
//               A B R A C A D A B R  
//              A B R A C A D A B R A 
//

#ifndef XML_h
#define XML_h

// system includes
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/TransService.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>

#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

#include <string>
#include <stdexcept>
#include <set>
#include <list>
#include <vector>
#include <map>

#if defined(XERCES_NEW_IOSTREAMS)
#include <iostream>
#else
#include <iostream.h>
#endif
#include "Exception.h"


#define tc(buf) xercesc::XMLString::transcode(buf)
#define xr(buf) xercesc::XMLString::release(buf)

// Error codes
enum {
    ERROR_ARGS = 1,
    ERROR_XERCES_INIT,
    ERROR_PARSE,
    ERROR_EMPTY_DOCUMENT
};
namespace crispr {
    namespace xml {
        typedef std::vector<std::string> IDVector;
        typedef std::map<std::string, IDVector > Spacer2SourceMap;
        typedef std::map<std::string, std::string> XMLIDMap;
        typedef std::set<std::string> StringSet;
        class base {
        public:
            //constructor / destructor
            base(void);
            ~base(void);
            
            // funtions used to keep constructor and destructor clean
            // and so the inherated classes can use them
            void init(void);
            void alloc(void);
            void dealloc(void);
            void release(void);
            //
            // Generic get
            //
            // grep ATTLIST crass.dtd | perl -ne 's/[^ ]* [^ ]* ([^ ]*) .*/\1/ ;chomp; my $original = $_; s/\b(\w)/\U$1/g; print "inline XMLCh * attr_$_(void) { return ATTR_$original; }\n";' | sort | uniq
            // grep ELEMENT crass.dtd | perl -ne 's/[^ ]* ([^ ]*) .*/\1/ ;chomp; my $original = $_; s/\b(\w)/\U$1/g; print "inline XMLCh * tag_$_(void) { return TAG_$original; }\n";' |sort | uniq
            
            inline XMLCh * attr_Accession(void) { return ATTR_accession; }
            inline XMLCh * attr_Cid(void) { return ATTR_cid; }
            inline XMLCh * attr_Confcnt(void) { return ATTR_confcnt; }
            inline XMLCh * attr_Cov(void) { return ATTR_cov; }
            inline XMLCh * attr_Directjoin(void) { return ATTR_directjoin; }
            inline XMLCh * attr_Drconf(void) { return ATTR_drconf; }
            inline XMLCh * attr_Drid(void) { return ATTR_drid; }
            inline XMLCh * attr_Drseq(void) { return ATTR_drseq; }
            inline XMLCh * attr_Flid(void) { return ATTR_flid; }
            inline XMLCh * attr_Gid(void) { return ATTR_gid; }
            inline XMLCh * attr_Seq(void) { return ATTR_seq; }
            inline XMLCh * attr_Soid(void) { return ATTR_soid; }
            inline XMLCh * attr_Spid(void) { return ATTR_spid; }
            inline XMLCh * attr_Totcnt(void) { return ATTR_totcnt; }
            inline XMLCh * attr_Type(void) { return ATTR_type; }
            inline XMLCh * attr_Url(void) { return ATTR_url; }
            inline XMLCh * attr_Version(void) { return ATTR_version; }
            
            inline XMLCh * tag_Assembly(void) { return TAG_assembly; }
            inline XMLCh * tag_Bf(void) { return TAG_bf; }
            inline XMLCh * tag_Bflankers(void) { return TAG_bflankers; }
            inline XMLCh * tag_Bs(void) { return TAG_bs; }
            inline XMLCh * tag_Bspacers(void) { return TAG_bspacers; }
            inline XMLCh * tag_Command(void) { return TAG_command; }
            inline XMLCh * tag_Consensus(void) { return TAG_consensus; }
            inline XMLCh * tag_Contig(void) { return TAG_contig; }
            inline XMLCh * tag_Crispr(void) { return TAG_crispr; }
            inline XMLCh * tag_Cspacer(void) { return TAG_cspacer; }
            inline XMLCh * tag_Data(void) { return TAG_data; }
            inline XMLCh * tag_Dr(void) { return TAG_dr; }
            inline XMLCh * tag_Drs(void) { return TAG_drs; }
            inline XMLCh * tag_Epos(void) { return TAG_epos; }
            inline XMLCh * tag_Ff(void) { return TAG_ff; }
            inline XMLCh * tag_Fflankers(void) { return TAG_fflankers; }
            inline XMLCh * tag_File(void) { return TAG_file; }
            inline XMLCh * tag_Flanker(void) { return TAG_flanker; }
            inline XMLCh * tag_Flankers(void) { return TAG_flankers; }
            inline XMLCh * tag_Fs(void) { return TAG_fs; }
            inline XMLCh * tag_Fspacers(void) { return TAG_fspacers; }
            inline XMLCh * tag_Group(void) { return TAG_group; }
            inline XMLCh * tag_Metadata(void) { return TAG_metadata; }
            inline XMLCh * tag_Name(void) { return TAG_name; }
            inline XMLCh * tag_Notes(void) { return TAG_notes; }
            inline XMLCh * tag_Program(void) { return TAG_program; }
            inline XMLCh * tag_Source(void) { return TAG_source; }
            inline XMLCh * tag_Sources(void) { return TAG_sources; }
            inline XMLCh * tag_Spos(void) { return TAG_spos; }
            inline XMLCh * tag_Spacer(void) { return TAG_spacer; }
            inline XMLCh * tag_Spacers(void) { return TAG_spacers; }
            inline XMLCh * tag_Version(void) { return TAG_version; }
            
            
            
        private:            
            // grep ATTLIST crass.dtd | sed -e "s%[^ ]* [^ ]* \([^ ]*\) .*%XMLCh\* ATTR_\1;%" | sort | uniq
            // grep ELEMENT crass.dtd | sed -e "s%[^ ]* \([^ ]*\) .*%XMLCh\* TAG_\1;%" | sort | uniq
            XMLCh * ATTR_accession;
            XMLCh * ATTR_cid;
            XMLCh * ATTR_confcnt;
            XMLCh * ATTR_cov;
            XMLCh * ATTR_directjoin;
            XMLCh * ATTR_drconf;
            XMLCh * ATTR_drid;
            XMLCh * ATTR_drseq;
            XMLCh * ATTR_flid;
            XMLCh * ATTR_gid;
            XMLCh * ATTR_seq;
            XMLCh * ATTR_soid;
            XMLCh * ATTR_spid;
            XMLCh * ATTR_totcnt;
            XMLCh * ATTR_type;
            XMLCh * ATTR_url;
            XMLCh * ATTR_version;
            
            XMLCh * TAG_assembly;
            XMLCh * TAG_bf;
            XMLCh * TAG_bflankers;
            XMLCh * TAG_bs;
            XMLCh * TAG_bspacers;
            XMLCh * TAG_command;
            XMLCh * TAG_consensus;
            XMLCh * TAG_contig;
            XMLCh * TAG_crispr;
            XMLCh * TAG_cspacer;
            XMLCh * TAG_data;
            XMLCh * TAG_dr;
            XMLCh * TAG_drs;
            XMLCh * TAG_epos;
            XMLCh * TAG_ff;
            XMLCh * TAG_fflankers;
            XMLCh * TAG_file;
            XMLCh * TAG_flanker;
            XMLCh * TAG_flankers;
            XMLCh * TAG_fs;
            XMLCh * TAG_fspacers;
            XMLCh * TAG_group;
            XMLCh * TAG_metadata;
            XMLCh * TAG_name;
            XMLCh * TAG_notes;
            XMLCh * TAG_program;
            XMLCh * TAG_source;
            XMLCh * TAG_sources;
            XMLCh * TAG_spacer;
            XMLCh * TAG_spacers;
            XMLCh * TAG_spos;
            XMLCh * TAG_version;
            
        };
        
        class reader : virtual public base {
        public:
            
            // default constructor
            reader();
            ~reader();
            
            
            // the reader should have virtual functions for overloading  
            
            
            // Parsing functions
            xercesc::DOMDocument * setFileParser(const char * xmlFile);
            
            //DOMDocument Creation returns root node
            // should be the same as set file parser
            void parseXMLFile(std::string XMLFile);
            
            
            // iterate through groups
            
            
            
            //
            // Working functions
            //
            void parseXMLFile(std::string XMLFile, 
                              std::string& wantedGroup, 
                              std::string& directRepeat,
                              StringSet& wantedContigs,
                              StringSet& wantedSpacers
                              );
            
            xercesc::DOMElement * getWantedGroupFromRoot(xercesc::DOMElement * currentElement, 
                                                         std::string& wantedGroup, 
                                                         std::string&  directRepeat
                                                         );
            
            
            xercesc::DOMElement * parseGroupForAssembly(xercesc::DOMElement* currentElement
                                                        );
            
            void parseAssemblyForContigIds(xercesc::DOMElement* parentNode, 
                                           StringSet& wantedReads, 
                                           Spacer2SourceMap& spacersForAssembly,
                                           XMLIDMap& source2acc,
                                           StringSet& wantedContigs
                                           );
            /** Iterate through all spacers for a contig and collecting source accessions  
             *  @param parentNode The contig node from the DOM tree 
             *  @param wantedReads a container to store the source accessions in
             *  @param spacersForAssembly A container containing a list of all sources for each spacer
             *  @param source2acc A container containing a mapping between source IDs and source accessions 
             */
            void getSourceIdForAssembly(xercesc::DOMElement* parentNode, 
                                        StringSet& wantedReads,
                                        Spacer2SourceMap& spacersForAssembly,
                                        XMLIDMap& source2acc
                                        );
            
            /** Get a list of sources for a group 
             *  @param container An associative container to write the sources to. 
             *  The container must have both key and value types as XMLCh *
             *  The container must overload reference operator[]
             *  @param parentNode The parent node for the sources for iteration
             */
            template <class C>
            void getSourcesForGroup(C& container, xercesc::DOMElement * parentNode) {
                
                if (xercesc::XMLString::equals(tag_Sources(), parentNode->getTagName())) {
                    for (xercesc::DOMElement * currentNode = parentNode->getFirstElementChild(); 
                         currentNode != NULL; 
                         currentNode = currentNode->getNextElementSibling()) {
                        
                        
                        char * current_source_id = tc(currentNode->getAttribute(attr_Soid()));
                        char * current_source_acc = tc(currentNode->getAttribute(attr_Accession()));
                        container[current_source_id] = current_source_acc;
                        xr(&current_source_id);
                        xr(&current_source_acc);
                    }
                } else {
                    throw crispr::xml_exception(__FILE__,
                                                __LINE__,
                                                __PRETTY_FUNCTION__,
                                                "Parent not 'sources' tag");
                }
                
                
            }
            /** Get a list of source identifiers for all spacers
             *  @param container An associative container that maps a single
             *  key (the spacer) to a list of sources
             *  @param parentNode The parent node for the spacer tags
             */
            template <class C>
            void mapSacersToSourceID(C& container, xercesc::DOMElement * parentNode) {
                // each spacer
                for (xercesc::DOMElement * currentNode = parentNode->getFirstElementChild(); 
                     currentNode != NULL; 
                     currentNode = currentNode->getNextElementSibling()) {
                    
                    char * spid = tc(currentNode->getAttribute(attr_Spid()));
                    // each source
                    for (xercesc::DOMElement * sp_source = currentNode->getFirstElementChild(); 
                         sp_source != NULL; 
                         sp_source = sp_source->getNextElementSibling()) {
                        
                        char * soid = tc(sp_source->getAttribute(attr_Soid()));
                        container[spid].push_back(soid);
                        xr(&soid);
                    }
                    xr(&spid);
                }
            }
            
        private:
            xercesc::XercesDOMParser * XR_FileParser;			// parsing object
            
        };
        
        class writer : virtual public base {
            
            //members
            xercesc::DOMDocument * XW_DocElem;
            int XW_CurrentSourceId;
            
        public:
            
            //constructor/destructor
            writer();
            ~writer();
            
            /** Create an in-memory representation of a crispr file   
             *  @param rootElement Name for the root element 
             *  @param versionNumber version for the crispr file to have
             *  @param errorNumber an integer for saving any error codes produced during document creation
             *  @return The xercesc::DOMElement for the root node or NULL on failure
             */
            xercesc::DOMElement * createDOMDocument(std::string rootElement, std::string versionNumber, int& errorNumber );
            
            xercesc::DOMElement * createDOMDocument(const char * rootElement, const char * versionNumber, int& errorNumber );
            
            /** add a 'metadata' tag to 'group'   
             *  @param parentNode the xercesc::DOMElement of the 'group' tag 
             *  @return  the xercesc::DOMElement of the 'metadata' tag
             */
            xercesc::DOMElement * addMetaData(xercesc::DOMElement * parentNode);
            
            /** add a 'metadata' tag to 'group' with notes  
             *  @param parentNode the xercesc::DOMElement of the 'group' tag
             *  @param notes freeform notes that the user can add in 
             *  @return  the xercesc::DOMElement of the 'metadata' tag
             */
            xercesc::DOMElement * addMetaData(std::string notes, xercesc::DOMElement * parentNode);
            
            /** add in files referenced by this group  
             *  @param type The type of reference file.  Must be one of image|sequence|log|data
             *  @param url path to the file
             *  @param parentNode xercesc::DOMElement of the 'metadata' tag
             */
            void addFileToMetadata(std::string type, std::string url, xercesc::DOMElement * parentNode);
            
            /** add extra notes to the 'metadata'  
             *  @param notes freeform notes added by the user
             *  @param parentNode xercesc::DOMElement of the 'metadata' tag
             */
            void addNotesToMetadata(std::string notes, xercesc::DOMElement * parentNode);
            
            /** add a 'group' to the root element  
             *  @param gID The unique group identifier
             *  @param drConsensus The direct repeat concensus sequence for this group
             *  @param parentNode xercesc::DOMElement of the root element
             */
            xercesc::DOMElement * addGroup(std::string& gID, std::string& drConsensus, xercesc::DOMElement * parentNode);
            
            /** add the 'data' to 'group'. This automatically creates the child nodes for the 'sources' 'drs' and 'spacers' tags  
             *  @param parentNode the 'group' xercesc::DOMElement
             *  @return The xercesc::DOMElement of the 'data' tag   
             */
            xercesc::DOMElement * addData(xercesc::DOMElement * parentNode);
            
            /** add the 'assembly' to 'group'   
             *  @param parentNode the 'group' xercesc::DOMElement
             *  @return The xercesc::DOMElement of the 'assembly' tag   
             */
            xercesc::DOMElement * addAssembly(xercesc::DOMElement * parentNode);
            
            /** add a direct repeat 'dr' tag to the 'drs' tag   
             *  @param drid The unique DR id for this group
             *  @param seq The sequence of the direct repeat in its lowest lexicographical form
             *  @param parentNode The xercesc::DOMElement of the 'drs' tag 
             */
            void addDirectRepeat(std::string& drid, std::string& seq, xercesc::DOMElement * parentNode);
            
            /** add a 'spcaer' tag to the 'spacers'   
             *  @param seq sequence of the spacer in the form that would appear if the direct repeat is in its lowest lexicographical form
             *  @param spid  the unique spacer identifier for this group
             *  @param parentNode the xercesc::DOMElement of the 'spacers' tag
             *  @param cov The coverage of the spacer. Defaults to zero
             *  @return the xercesc::DOMElement for the 'spacer' tag
             */
            xercesc::DOMElement * addSpacer(std::string& seq, std::string& spid, xercesc::DOMElement * parentNode, std::string cov = "0" );
            
            /** create a 'flankers' tag in 'data'   
             *  @param parentNode the xercesc::DOMElement of the 'data' tag
             *  @return the xercesc::DOMElement of the 'flankers' tag
             */
            xercesc::DOMElement * createFlankers(xercesc::DOMElement * parentNode);
            
            /** add a 'flanker' tag to the 'flankers' tag   
             *  @param seq sequence of the flanker in the form that would appear if the direct repeat is in its lowest lexicographical form
             *  @param flid the unique flanker identifier for this group
             *  @param parentNode the xercesc::DOMElement of the 'flankers' tag 
             *  @return the xercesc::DOMElement of the 'flanker' tag   
             */
            xercesc::DOMElement * addFlanker(std::string& seq, std::string& flid, xercesc::DOMElement * parentNode);
            
            /** add a 'contig' to an 'assembly'   
             *  @param cid a unique contig id for this group
             *  @param parentNode the xercesc::DOMElement of the 'assembly' tag
             *  @return the xercesc::DOMElement of the 'contig' tag   
             */
            xercesc::DOMElement * addContig(std::string& cid, xercesc::DOMElement * parentNode);
            
            /** add the concensus sequence to the contig   
             *  @param concensus A string of DNA characters representing the joined sequence of all the spacers and direct repeats for this contig
             *  @param parentNode the xercesc::DOMElement of the 'contig' tag  
             */
            void createConsensus(std::string& concensus, xercesc::DOMElement * parentNode);
            
            /** Add a 'cspacer' to a 'contig'   
             *  @param spid Unique identifier for the spacer.  should be the same as listed in the 'spacers' tag in 'data'
             *  @param parentNode the xercesc::DOMElement of the 'contig' tag
             *  @return the xercesc::DOMElement of the 'cspacer' tag  
             */
            xercesc::DOMElement * addSpacerToContig(std::string& spid, xercesc::DOMElement * parentNode);
            
            /** use to create a backward spacers ('bspacers') or forward spacers ('fspacers') child elements of 'cspacer'   
             *  @param tag A string of either "bspacers" or "fspacers"
             *  @return the xercesc::DOMElement of either "bspacers" or "fspacers"  
             */
            xercesc::DOMElement * createSpacers(std::string tag);
            
            /** A convienience method that calls createSpacers, Used only for making the code more explicit   
             *  @param tag A string of either "bflankers" or "fflankers"
             *  @return the xercesc::DOMElement of either "bflankers" or "fflankers"  
             */
            xercesc::DOMElement * createFlankers(std::string tag);
            
            /** add either a backward spacer (bs) or forward spacer (fs) tags to a cspacer tag   
             *  @param tag A string that describes the type of association ('bs' or 'fs')
             *  @param spid The unique spacer id for the link.  Should be the same as an spid listed in 'spacers' tag inside 'data'
             *  @param drid The unique direct repeat id for the DR that sits inbetween the two spacers
             *  @param drconf
             *  @param parentNode The xercesc::DOMElement corresponding to one of bspacers, fspacers  
             */
            void addSpacer(std::string tag, std::string& spid, std::string& drid, std::string& drconf, xercesc::DOMElement * parentNode);
            
            /** add either a backward flanker (bf) or forward flanker (ff) tags to cspacer   
             *  @param tag A string that describes the type of association ('bf' or 'ff')
             *  @param flid The unique flanker id for the link.  Should be the same as an spid listed in 'fankers' tag inside 'data'
             *  @param drconf 
             *  @param directjoin
             *  @param parentNode The xercesc::DOMElement corresponding to one of bflankers, fflankers  
             */
            void addFlanker(std::string tag, std::string& flid, std::string& drconf, std::string& directjoin, xercesc::DOMElement * parentNode);
            
            /** create the sources tag for a group    
             *  @param parentNode The xercesc::DOMElement for the 'group' tag
             *  @return The xercesc::DOMElement for the 'sources' tag  
             */
            xercesc::DOMElement * addSources(xercesc::DOMElement * parentNode);
            
            /** add a 'source' tag for the sources   
             *  @param accession The accession for the source as it would appear in a fasta file
             *  @param soid The unique source identifier for this source.  Ideally this should be short, containing sharacters and
             *              numbers for future reference within the cirpsr file.
             *  @param parentNode The xercesc::DOMElement of the 'sources' tag
             *  @return The xercesc::DOMElement of teh 'source' tag  
             */
            xercesc::DOMElement * addSource(std::string accession, std::string soid, xercesc::DOMElement * parentNode);
            
            /** add a source tag for a spacer   
             *  @param soid The unique source identifier for this source. Sould be the same as listed in the 'sources' inside 'data'
             *  @param parentNode The xercesc::DOMElement of the 'spacer' that was fould inside this source
             *  @return The xercesc::DOMElement of the 'source' tag  
             */
            xercesc::DOMElement * addSpacerSource(std::string soid, xercesc::DOMElement * parentNode);
            
            /** add start and end positions for 'source' in 'spacer'   
             *  @param start The start position in the source for the spacer
             *  @param end The end position in the source for the spacer
             *  @param parentNode The 'source' tag to the spacer  
             */
            void addStartAndEndPos(std::string start, std::string end, xercesc::DOMElement * parentNode);
            
            /** add a 'program' tag to 'metadata'   
             *  @param parentNode The xercesc::DOMElement of the 'metadata' tag
             *  @return The xercesc::DOMElement of the 'program' tag  
             */
            xercesc::DOMElement * addProgram(xercesc::DOMElement * parentNode);
            
            /** add a 'name' tag to 'program'   
             *  @param progName The name of the program that called this CRISPR
             *  @param parentNode The xercesc::DOMElement of the 'program' tag
             */
            void addProgName(std::string progName, xercesc::DOMElement * parentNode);
            
            /** add a 'version' tag to 'program'   
             *  @param progVersion The version of the program that called this CRISPR
             *  @param parentNode The xercesc::DOMElement of the 'program' tag
             */
            void addProgVersion(std::string progVersion, xercesc::DOMElement * parentNode);
            
            /** add a 'command' tag to 'program'   
             *  @param progCommand The command line options used to call this CRISPR
             *  @param parentNode The xercesc::DOMElement of the 'program' tag 
             */
            void addProgCommand(std::string progCommand, xercesc::DOMElement * parentNode);
            
            /** print the current document to file   
             *  @param outFileName The name of the output file
             */
            bool printDOMToFile(std::string outFileName );
            
            /** print the current document to screen   
             */
            bool printDOMToScreen(void);
            
            bool printDOMToFile(std::string outFileName, xercesc::DOMDocument * domDoc );
            
            bool printDOMToScreen( xercesc::DOMDocument * domDoc);
            
            /** convienience method to return the root element of the current document   
             *  @return The xercesc::DOMElement for the root ('crispr') tag  
             */
            inline xercesc::DOMElement * getRootElement(void)
            {
                return XW_DocElem->getDocumentElement();
            }
            
            /** convienience method to return the current document   
             *  @return The xercesc::DOMDocument for this writer  
             */
            inline xercesc::DOMDocument * getDocumentObj(void)
            {
                return XW_DocElem;
            }
            
            
        };
        class parser : public reader, public writer {

            public:
                // constructor
                parser();
                ~parser();
        };
    } //xml
} //crispr


#endif //XML_h
