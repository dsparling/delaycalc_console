// DelayCalculator.cpp
#include "DelayCalculator.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// constants
const string PROGRAM_NAME = "delaycalc";
const string VERSION_NUMBER = "0.02";

// vars

DelayCalculator::DelayCalculator()
{
  // initialize object
  bpm              = 120;
  precision        = 3;

}

DelayCalculator::DelayCalculator(int bpm_arg)
{
  // initialize object
  bpm              = bpm_arg;
  precision        = 3;

}

DelayCalculator::~DelayCalculator()
{
}

void DelayCalculator::calculateDelay()
{
  double raw = 60000 / bpm;

  // set values
  std_whole = raw * 4;
  std_half = raw * 2;
  std_quarter = raw;
  std_eigth = raw / 2;
  std_sixteenth = raw / 4;
  std_thirtysecond = raw / 8;
  // dotted
  dotted_whole = (raw * 4) * 1.5;
  dotted_half = (raw * 2) * 1.5;
  dotted_quarter = raw * 1.5;
  dotted_eigth = (raw / 2) * 1.5;
  dotted_sixteenth = (raw / 4) * 1.5;
  dotted_thirtysecond = (raw / 8) * 1.5;
  // triplet
  triplet_whole = (raw * 4) * 2/3;
  triplet_half = (raw * 2) * 2/3;
  triplet_quarter = raw * 2/3;
  triplet_eigth = (raw / 2) * 2/3;
  triplet_sixteenth = (raw / 4) * 2/3;
  triplet_thirtysecond = (raw / 8) * 2/3;
}

void DelayCalculator::printDelay()
{
  double raw = 60000 / bpm;

  // print info
  cout << "BPM: "      << bpm << endl;

  // print
  // now setprecision() will set number of decimal places
  cout.setf(ios::fixed);

  if (precision == 1 )
    cout << setprecision(1);
  else if (precision == 2 )
    cout << setprecision(2);
  else if (precision == 3 )
    cout << setprecision(3);
  else if (precision == 4 )
    cout << setprecision(4);
  else if (precision == 5 )
    cout << setprecision(5);
  else
    cout << setprecision(3);

  // std
  cout << "std_whole: " << std_whole << endl;
  cout << "std_half: " << std_half << endl;
  cout << "std_quarter: " << std_quarter << endl;
  cout << "std_eigth: " << std_eigth << endl;
  cout << "std_sixteenth: " << std_sixteenth << endl;
  cout << "std_thirtysecond: " << std_thirtysecond << endl;
  // dotted
  cout << "dotted_whole: " << dotted_whole << endl;
  cout << "dotted_half: " << dotted_half << endl;
  cout << "dotted_quarter: " << dotted_quarter << endl;
  cout << "dotted_eigth: " << dotted_eigth << endl;
  cout << "dotted_sixteenth: " << dotted_sixteenth << endl;
  cout << "dotted_thirtysecond: " << dotted_thirtysecond << endl;
  // triplet
  cout << "triplet_whole: " << triplet_whole << endl;
  cout << "triplet_half: " << triplet_half << endl;
  cout << "triplet_quarter: " << triplet_quarter << endl;
  cout << "triplet_eigth: " << triplet_eigth << endl;
  cout << "triplet_sixteenth: " << triplet_sixteenth << endl;
  cout << "triplet_thirtysecond: " << triplet_thirtysecond << endl;
 
}

void DelayCalculator::writeDelay()
{

  double raw = 60000 / bpm;

  // write to file
  ofstream outfile("delay.out", ios::out);
  if(! outfile)
  {
    cout << "Error opening output file" << endl;
    return;
  }

  // file opened successfully
  cout << "File delay.out created" << endl;

  // print info
  outfile << "BPM: "      << bpm << endl;

  // now setprecision() will set number of decimal places
  outfile.setf(ios::fixed);

  if (precision == 1 )
    outfile << setprecision(1);
  else if (precision == 2 )
    outfile << setprecision(2);
  else if (precision == 3 )
    outfile << setprecision(3);
  else if (precision == 4 )
    outfile << setprecision(4);
  else if (precision == 5 )
    outfile << setprecision(5);
  else 
    outfile << setprecision(3);

  // std
  outfile << "std_whole: " << std_whole << endl;
  outfile << "std_half: " << std_half << endl;
  outfile << "std_quarter: " << std_quarter << endl;
  outfile << "std_eigth: " << std_eigth << endl;
  outfile << "std_sixteenth: " << std_sixteenth << endl;
  outfile << "std_thirtysecond: " << std_thirtysecond << endl;
  // dotted
  outfile << "dotted_whole: " << dotted_whole << endl;
  outfile << "dotted_half: " << dotted_half << endl;
  outfile << "dotted_quarter: " << dotted_quarter << endl;
  outfile << "dotted_eigth: " << dotted_eigth << endl;
  outfile << "dotted_sixteenth: " << dotted_sixteenth << endl;
  outfile << "dotted_thirtysecond: " << dotted_thirtysecond << endl;
  // triplet
  outfile << "triplet_whole: " << triplet_whole << endl;
  outfile << "triplet_half: " << triplet_half << endl;
  outfile << "triplet_quarter: " << triplet_quarter << endl;
  outfile << "triplet_eigth: " << triplet_eigth << endl;
  outfile << "triplet_sixteenth: " << triplet_sixteenth << endl;
  outfile << "triplet_thirtysecond: " << triplet_thirtysecond << endl;

  outfile.close();
}

void DelayCalculator::setBPM(int bpm_arg)
{
  bpm = bpm_arg;
}

void DelayCalculator::setPrecision(int precision_arg)
{
  if( precision_arg <= 0 || precision_arg > 5 )
    precision_arg = 3;

  precision = precision_arg;
}

int DelayCalculator::getBPM()
{
  return bpm;
}

int DelayCalculator::getPrecision()
{
  return precision;
}

void DelayCalculator::printHelp()
{
  cout << "Usage: delaycalc -b <bpm> [OPTIONS]" << endl;
  cout << "e.g: delaycalc -b 120" << endl;
  cout << "e.g: delaycalc -b 120 -d 3" << endl;
  cout << endl;
  cout << "Options:" << endl;
  cout << "  -b <bpm>                  beats per minute" << endl;
  cout << "  -h, --help                print this help" << endl;
  cout << "  -o, --output              write output to calc.out" << endl;
  cout << "  -p <num_decimal_places>   precision of calculation display (1-5, default 3)" << endl;
  cout << "  -V, --verbose             be verbose" << endl;
  cout << "  -v, --version             print version number" << endl;
  cout << "  -w, --warranty            show warranty and copyright" << endl;
}

void DelayCalculator::printVersion()
{
  cout << PROGRAM_NAME << " " << VERSION_NUMBER << endl;
}

void DelayCalculator::printWarranty()
{
  cout << "  Copyright (c) 2005-2015 by" << endl;
  cout << "  Douglas S Sparling <doug@dougsparling.com>" << endl;
  cout << endl;
  cout << "    This program is free software; you can redistribute it and/or" << endl;
  cout << "modify it under the terms of the GNU General Public License version 2" << endl;
  cout << "as published by the Free Software Foundation." << endl;
  cout << endl;
  cout << "    This program is distributed in the hope that it will be useful," << endl;
  cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of" << endl;
  cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU" << endl;
  cout << "General Public License for more details." << endl;
  cout << endl;
  cout << "    You should have received a copy (refer to the file COPYING) of the" <<  endl;
  cout << "GNU General Public License along with this program; if not, write to" << endl;
 cout << "the Free Software Foundation, Inc., 59 Temple Place - Suite 330," << endl;
  cout << "Boston, MA 02111-1307, USA." << endl;
  cout << endl << endl;
  cout << "Report bugs to doug@dougsparling.com" << endl;
}
