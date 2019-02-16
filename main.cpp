#include <iostream>
#include <fstream> // read and write files
#include <string>
#include <locale>
#include <cmath>
// Assignment 1, take in a file of nucleotides (A,T,C,G) and replicate them with the same probabilities.
using namespace std;

double setStringLength(double inMean, double inDeviation)
{
  double gDistribution = (sqrt(2 * exp(1.0 / ((double)rand() / (RAND_MAX) - 1))) ) * (cos(2.0 * 3.14 * ((double)rand() / (RAND_MAX) - 1))); // calculates the gaussian dstribution
  double newLength = inDeviation * gDistribution + inMean;
}

int main(int argc, char** argv)
{
  string fileName = "";

  if(argc > 1) // checks if there is user input
  {
    fileName = argv[1]; // Accepts the name of a text file from the commans line argument. The file will contain an arituary amount of DNA strings

  }
  fstream DNAfile(fileName);

  int numOf_A = 0; //stores the number of each ocuting nucleotide
  int numOf_T = 0;
  int numOf_C = 0;
  int numOf_G = 0;

  int numOf_AA = 0;
  int numOf_AT = 0;
  int numOf_AC = 0;
  int numOf_AG = 0;

  int numOf_TA = 0;
  int numOf_TT = 0;
  int numOf_TC = 0;
  int numOf_TG = 0;

  int numOf_CA = 0;
  int numOf_CT = 0;
  int numOf_CC = 0;
  int numOf_CG = 0;

  int numOf_GA = 0;
  int numOf_GT = 0;
  int numOf_GC = 0;
  int numOf_GG = 0;

  string nucleotides = ""; //string that holds the line of nucleotides from the text file
  int sumLineLengths = 0;
  int numLines = 0;

 if (DNAfile.is_open())//opens the file
 {
    while (getline(DNAfile, nucleotides))// interates through the lines in the text file
    {
      numLines += 1;
      for(int i = 0; i < nucleotides.length(); i++)// iterates though the letters of the line and records their occurance
      {
        toupper(nucleotides[i]); //sets the letters to uppercase
        sumLineLengths += 1; // records the sum of the lengths of the DNA strings
        if (nucleotides[i] == 'A')
        {
          numOf_A += 1;
        }
        else if(nucleotides[i] == 'T')
        {
          numOf_T += 1;
        }
        else if(nucleotides[i] == 'C')
        {
          numOf_C += 1;
        }
        else if(nucleotides[i] == 'G')
        {
          numOf_G += 1;
        }

        if(i < nucleotides.length() - 1) //prevents out of bounds exception
        {
  // A
          if (nucleotides[i] == 'A' && nucleotides[i + 1] == 'A') // records the number of each bigram
          {
            numOf_AA += 1;
          }
          else if (nucleotides[i] == 'A' && nucleotides[i + 1] == 'T')
          {
            numOf_AT += 1;
          }
          else if (nucleotides[i] == 'A' && nucleotides[i + 1] == 'C')
          {
            numOf_AC += 1;
          }
          else if (nucleotides[i] == 'A' && nucleotides[i + 1] == 'G')
          {
            numOf_AG += 1;
          }
  // T
          else if (nucleotides[i] == 'T' && nucleotides[i + 1] == 'A')
          {
            numOf_TA += 1;
          }
          else if (nucleotides[i] == 'T' && nucleotides[i + 1] == 'T')
          {
            numOf_TT += 1;
          }
          else if (nucleotides[i] == 'T' && nucleotides[i + 1] == 'C')
          {
            numOf_TC += 1;
          }
          else if (nucleotides[i] == 'T' && nucleotides[i + 1] == 'G')
          {
            numOf_TG += 1;
          }
  // C
          else if (nucleotides[i] == 'C' && nucleotides[i + 1] == 'A')
          {
            numOf_CA += 1;
          }
          else if (nucleotides[i] == 'C' && nucleotides[i + 1] == 'T')
          {
            numOf_CT += 1;
          }
          else if (nucleotides[i] == 'C' && nucleotides[i + 1] == 'C')
          {
            numOf_CC += 1;
          }
          else if (nucleotides[i] == 'C' && nucleotides[i + 1] == 'G')
          {
            numOf_CG += 1;
          }
  // G
          else if (nucleotides[i] == 'G' && nucleotides[i + 1] == 'A')
          {
            numOf_GA += 1;
          }
          else if (nucleotides[i] == 'G' && nucleotides[i + 1] == 'T')
          {
            numOf_GT += 1;
          }
          else if (nucleotides[i] == 'G' && nucleotides[i + 1] == 'C')
          {
            numOf_GC += 1;
          }
          else if (nucleotides[i] == 'G' && nucleotides[i + 1] == 'G')
          {
            numOf_GG += 1;
          }
        }
      }
    }

    //Calculations
    double totalNumNucleotides = numOf_A + numOf_C + numOf_G + numOf_T;
    double prob_A = numOf_A / totalNumNucleotides * 100.0; // probability of A
    double prob_T = numOf_T / totalNumNucleotides * 100.0; // probability of T
    double prob_C = numOf_C / totalNumNucleotides * 100.0; // probability of C
    double prob_G = numOf_G / totalNumNucleotides * 100.0; // probability of G

    double totalNumBigrams = numOf_AA + numOf_AT + numOf_AC + numOf_AG + numOf_TA + numOf_TT + numOf_TC + numOf_TG + numOf_CA + numOf_CT + numOf_CC + numOf_CG + numOf_GA + numOf_GT + numOf_GC + numOf_GG;
    double prob_AA = numOf_AA / totalNumBigrams * 100.0; // probability of AA
    double prob_AT = numOf_AT / totalNumBigrams * 100.0;// probability of AT
    double prob_AC = numOf_AC / totalNumBigrams * 100.0;// probability of AC
    double prob_AG = numOf_AG / totalNumBigrams * 100.0;// probability of AG

    double prob_TA = numOf_TA / totalNumBigrams * 100.0;// probability of TA
    double prob_TT = numOf_TT / totalNumBigrams * 100.0;// probability of TT
    double prob_TC = numOf_TC / totalNumBigrams * 100.0;// probability of TC
    double prob_TG = numOf_TG / totalNumBigrams * 100.0;// probability of TG

    double prob_CA = numOf_CA / totalNumBigrams * 100.0;// probability of CA
    double prob_CT = numOf_CT / totalNumBigrams * 100.0;// probability of CT
    double prob_CC = numOf_CC / totalNumBigrams * 100.0;// probability of CC
    double prob_CG = numOf_CG / totalNumBigrams * 100.0;// probability of CG

    double prob_GA = numOf_GA / totalNumBigrams * 100.0;// probability of GA
    double prob_GT = numOf_GT / totalNumBigrams * 100.0;// probability of GT
    double prob_GC = numOf_GC / totalNumBigrams * 100.0;// probability of GC
    double prob_GG = numOf_GG / totalNumBigrams * 100.0;// probability of GG

    double meanLineLength = sumLineLengths / numLines; // calculates mean of the lengths of DNA strings


    double variance = 0;
    DNAfile.clear();
    DNAfile.seekg(0,DNAfile.beg);  // got back to the top of the file

    string lines = "";
    while(getline(DNAfile, lines))
    {
      variance = (lines.length() - meanLineLength) * (lines.length() - meanLineLength); // calculates variance
    }

    variance = variance / numLines;
    double StandardDev = sqrt(variance); // calculates standard deviationd

    ofstream outFile("EthanKennedy.out.txt");

    if(outFile.is_open())
    {
      outFile << "Name: Ethan Kennedy \n"; //Writes calculations to text file
      outFile << "Student ID: 2291686 \n";
      outFile << "Sum of the length of the DNA strings in the list : " << sumLineLengths << endl;
      outFile << "Mean of the length of the DNA strings in the list : " << meanLineLength << endl;
      outFile << "Variance of the length of the DNA strings in the list : " << variance << endl;
      outFile << "Standard Devation of the length of the DNA strings in the list : " << StandardDev << endl;
      outFile << "Probability of nucleotide being A : " << prob_A << endl;
      outFile << "Probability of nucleotide being T : " << prob_T << endl;
      outFile << "Probability of nucleotide being C : " << prob_C << endl;
      outFile << "Probability of nucleotide being G : " << prob_G << endl;
      outFile << "Probability of nucleotide bigram being AA : " << prob_AA << endl;
      outFile << "Probability of nucleotide bigram being AT : " << prob_AT << endl;
      outFile << "Probability of nucleotide bigram being AC : " << prob_AC << endl;
      outFile << "Probability of nucleotide bigram being AG : " << prob_AG << endl;
      outFile << "Probability of nucleotide bigram being TA : " << prob_TA << endl;
      outFile << "Probability of nucleotide bigram being TT : " << prob_TT << endl;
      outFile << "Probability of nucleotide bigram being TC : " << prob_TC << endl;
      outFile << "Probability of nucleotide bigram being TG : " << prob_TG << endl;
      outFile << "Probability of nucleotide bigram being CA : " << prob_CA << endl;
      outFile << "Probability of nucleotide bigram being CT : " << prob_CT << endl;
      outFile << "Probability of nucleotide bigram being CC : " << prob_CC << endl;
      outFile << "Probability of nucleotide bigram being CG : " << prob_CG << endl;
      outFile << "Probability of nucleotide bigram being GA : " << prob_GA << endl;
      outFile << "Probability of nucleotide bigram being GT : " << prob_GT << endl;
      outFile << "Probability of nucleotide bigram being GC : " << prob_GC << endl;
      outFile << "Probability of nucleotide bigram being GG : " << prob_GG << endl;

      //Makes the new set of DNA
      int newStringLength = 0;
      for(int j = 0; j < 1000; j++)// makes 1000 lines of A,T,C,G
      {
        newStringLength = (int)setStringLength(meanLineLength, variance); // sets the length of the lines
        for(int k = 0; k < newStringLength; k++)
        {
          //randimly choses nucleotide based on previous data
          double random = rand() % 100;
          if (random < prob_A)
          {
            outFile << "A";
          }
          else if(random < (prob_T + prob_A))
          {
            outFile << "T";
          }
          else if(random < (prob_C + prob_T + prob_A))
          {
            outFile << "C";
          }
          else
          {
            outFile << "G";
          }
        }
        outFile << endl;
      }

      DNAfile.close();// closes the files
      outFile.close();
    }
  }
}



// compute the sum, mean, variance and standard deviation of the length of the DNA strings in the list
