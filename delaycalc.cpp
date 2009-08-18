// delaycalc.cpp
#include "DelayCalculator.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

// function delcarations
void param_init(int, char *[]);

// variable declarations
char * endptr;
int bpm_param;
int precision_param;
bool print_help     = false;
bool print_version  = false;
bool print_warranty = false;
bool verbose        = false;
bool is_dulcimer    = false;
bool out_file       = false;
bool b_found        = false;

int main (int argc, char **argv)
{

  // check for parameters
  param_init(argc,argv);

  // create object
  DelayCalculator DC;

  // check for message flags
  if(print_help)
  {
    DC.printHelp();
    exit(0);
  } 
  else if(print_warranty)
  {
    DC.printVersion();
    DC.printWarranty();
    exit(0);
  }
  else if(print_version)
  {
    DC.printVersion();
    exit(0);
  }

  // set all params
  DC.setBPM(bpm_param);
  DC.setPrecision(precision_param);
  DC.calculateDelay();

  if( b_found ) 
  {

    if(out_file)
    {
      DC.writeDelay();
      if(verbose)
        DC.printDelay();
    } 
    else
    {
      DC.printDelay();
    }
  
  } else {
    DC.printHelp();
  }

  return 0;
}

void param_init(int argc,char *argv[])
{
  // first, get the parameters
  char *str;             // string pointer
  const char *sub = "-"; // substring pointer
  char *ptr;             // pointer for substring address
  char *pch;             // pointer for tokens
  int pos;               // element position for found substring

  for (int i = 1; i < argc; i++)
  {

    // bpm
    if (strcmp(argv[i], "-b") == 0)
    {
      if (i + 1 < argc)
      {
        // make sure "i+1" isn't another argument flag
        str = argv[i+1];
        ptr = strstr(str,sub);
        pos = (ptr - str);
        if( pos != 0 )
        {
          b_found = true;
          bpm_param = atoi(argv[++i]);
        }
      }
    }

    // help
    if ((strcmp(argv[i], "-h") == 0) ||
        (strcmp(argv[i], "--h") == 0) ||
        (strcmp(argv[i], "-help") == 0) ||
        (strcmp(argv[i], "--help") == 0)) {
      print_help = true;
    }

    // write to output file 'delay.out' 
    if ((strcmp(argv[i], "-o") == 0) ||
        (strcmp(argv[i], "--o") == 0) ||
        (strcmp(argv[i], "-output") == 0) ||
        (strcmp(argv[i], "--output") == 0)) {
      out_file = true;
    }

    // precision (precision)
    if (strcmp(argv[i], "-p") == 0)
    {
      if (i + 1 < argc)
      {
        // make sure "i+1" isn't another argument flag
        str = argv[i+1];
        ptr = strstr(str,sub);
        pos = (ptr - str);
        if( pos != 0 ) {
          precision_param = atoi(argv[++i]);
        }
      }
    }

    // verbose
    if ((strcmp(argv[i], "-V") == 0) ||
        (strcmp(argv[i], "--V") == 0) ||
        (strcmp(argv[i], "-verbose") == 0) ||
        (strcmp(argv[i], "--verbose") == 0)) {
      verbose = true;
    }

    // version and credits
    if ((strcmp(argv[i], "-v") == 0) ||
        (strcmp(argv[i], "--v") == 0) ||
        (strcmp(argv[i], "-version") == 0) ||
        (strcmp(argv[i], "--version") == 0)) {
      print_version = true;
    }

    // warranty
    if ((strcmp(argv[i], "-w") == 0) ||
        (strcmp(argv[i], "--w") == 0) ||
        (strcmp(argv[i], "-warranty") == 0) ||
        (strcmp(argv[i], "--warranty") == 0)) {
      print_version = true;
      print_warranty = true;
    }
 
  }
}
