#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BLASTNPlugin.h"


void BLASTNPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

}

void BLASTNPlugin::run() {}

void BLASTNPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";

 //blastp -query "+organism1+".faa -db "+organism2+".db -outfmt 6 > "+organism1+"_"+organism2+".txt"
 //makeblastdb -in PA14.txt -out PA14.db
 //blastn -db release10_bac_$i -query primers.txt -num_descriptions 50000 -num_alignments 50000 -evalue 50 -dust no -soft_masking false -word_size 8
myCommand += "blastn";
myCommand += " ";
myCommand += "-query";
myCommand += " ";
myCommand += std::string(PluginManager::prefix()) + "/" + parameters["query"] + " ";
myCommand += "-db";
myCommand += " ";
myCommand += std::string(PluginManager::prefix()) + "/" + parameters["db"] + " ";
if (parameters.count("outfmt") != 0) {
myCommand += "-outfmt";
myCommand += " ";
myCommand += parameters["outfmt"] + " ";
}
if (parameters.count("num_descriptions") != 0) {
myCommand += "-num_descriptions";
myCommand += " ";
myCommand += parameters["num_descriptions"] + " ";
}
if (parameters.count("num_alignments") != 0) {
myCommand += "-num_alignments";
myCommand += " ";
myCommand += parameters["num_alignments"] + " ";
}
if (parameters.count("evalue") != 0) {
myCommand += "-evalue";
myCommand += " ";
myCommand += parameters["evalue"] + " ";
}
if (parameters.count("dust") != 0) {
myCommand += "-dust";
myCommand += " ";
myCommand += parameters["dust"] + " ";
}
if (parameters.count("soft_masking") != 0) {
myCommand += "-soft_masking";
myCommand += " ";
myCommand += parameters["soft_masking"] + " ";
}
if (parameters.count("word_size") != 0) {
myCommand += "-word_size";
myCommand += " ";
myCommand += parameters["word_size"] + " ";
}
myCommand += ">";
myCommand += " ";
myCommand += outputfile;
std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<BLASTNPlugin> BLASTNPluginProxy = PluginProxy<BLASTNPlugin>("BLASTN", PluginManager::getInstance());
