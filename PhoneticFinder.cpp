#include <bits/stdc++.h>
#include "PhoneticFinder.hpp"
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <string>

// creates map of any mistake possible

std::map<std::string, vector<std::string>> mistakesDictionary()
{

    // this is a map, where the keys are strings and the values are strings
    std::map<std::string, vector<std::string>> spelling_mistakes;

    // insert v,w user
    spelling_mistakes["v"] = vector<string>{"V", "w", "W"};
    spelling_mistakes["w"] = vector<string>{"W", "v", "V"};

    // insert b, f, p user
    spelling_mistakes["b"] = vector<string>{"B", "f", "p", "F", "P"};
    spelling_mistakes["f"] = vector<string>{"F", "b", "p", "B", "P"};
    spelling_mistakes["p"] = vector<string>{"P", "b", "f", "B", "F"};

    // insert g, j user
    spelling_mistakes["g"] = vector<string>{"G", "j", "J"};
    spelling_mistakes["j"] = vector<string>{"J", "g", "G"};

    // insert c, k, q user
    spelling_mistakes["c"] = vector<string>{"C", "k", "q","K", "Q"};
    spelling_mistakes["k"] = vector<string>{"K", "c", "q", "C", "Q"};
    spelling_mistakes["q"] = vector<string>{"Q", "c", "k", "C", "K"};

    // insert s, z user
    spelling_mistakes["s"] = vector<string>{"S", "z", "Z"};
    spelling_mistakes["z"] = vector<string>{"Z", "s", "S"};

    // insert d, t user
    spelling_mistakes["d"] = vector<string>{"D", "t"};
    spelling_mistakes["t"] = vector<string>{"T", "d"};

    // insert o, u user
    spelling_mistakes["o"] = vector<string>{"O", "u"};
    spelling_mistakes["u"] = vector<string>{"U", "o"};

    // insert i, y user
    spelling_mistakes["i"] = vector<string>{"I", "y"};
    spelling_mistakes["y"] = vector<string>{"Y", "i"};
    
    // insert a
    spelling_mistakes["A"] = vector<string>{"a"};
    spelling_mistakes["a"] = vector<string>{"A"};

    spelling_mistakes["B"] = vector<string>{"b","P","p", "F", "f"};

    spelling_mistakes["C"] = vector<string>{"c", "k","K","q","Q"};

    spelling_mistakes["D"] = vector<string>{"d", "t", "T"};

    spelling_mistakes["e"] = vector<string>{"E"};
    spelling_mistakes["E"] = vector<string>{"e"};

    spelling_mistakes["F"] = vector<string>{"f", "b", "B", "p", "P"};

    spelling_mistakes["G"] = vector<string>{"g", "j", "J"};

    spelling_mistakes["H"] = vector<string>{"h"};
    spelling_mistakes["h"] = vector<string>{"H"};

    spelling_mistakes["I"] = vector<string>{"i", "y","Y"};

    spelling_mistakes["J"] = vector<string>{"j", "g","G"};

    spelling_mistakes["K"] = vector<string>{"k","c","C","q","Q"};

    spelling_mistakes["L"] = vector<string>{"l"};
    spelling_mistakes["l"] = vector<string>{"L"};

    spelling_mistakes["M"] = vector<string>{"m"};
    spelling_mistakes["m"] = vector<string>{"M"};

    spelling_mistakes["N"] = vector<string>{"n"};
    spelling_mistakes["n"] = vector<string>{"N"};

    spelling_mistakes["O"] = vector<string>{"o", "u","U"};

    spelling_mistakes["P"] = vector<string>{"p", "B", "F", "b", "f"};

    spelling_mistakes["Q"] = vector<string>{"q"};

    spelling_mistakes["R"] = vector<string>{"r"};
    spelling_mistakes["r"] = vector<string>{"R"};

    spelling_mistakes["S"] = vector<string>{"s","z","Z"};

    spelling_mistakes["T"] = vector<string>{"t", "d","D"};

    spelling_mistakes["U"] = vector<string>{"u","o","O"};

    spelling_mistakes["V"] = vector<string>{"v", "w","W"};

    spelling_mistakes["W"] = vector<string>{"w", "v", "V"};

    spelling_mistakes["X"] = vector<string>{"x"};
    spelling_mistakes["x"] = vector<string>{"X"};

    spelling_mistakes["Y"] = vector<string>{"y","i","I"};

    spelling_mistakes["Z"] = vector<string>{"z", "s", "S"};

    
    return spelling_mistakes;
}

vector<string> spaceSplitter(string line)
{
    // Vector of string to save tokens
    vector<string> tokens;

    // stringstream class check1
    stringstream check1(line);

    string intermediate;

    // Tokenizing w.r.t. space ' '
    while (getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }

    return tokens;
}

// checking if current word can be mistaken word
string isSimilarWord(string text_word, string find_word)
{
    map<string, vector<string>> mistakeDict = mistakesDictionary();
    bool foundLetter = false;
    for (size_t letter = 0; letter < find_word.size(); letter++)
    {
        if (find_word[letter] != text_word[letter])
        {

            string find_letter, text_letter;
            std::stringstream ss, rr;
            ss << find_word[letter];
            ss >> find_letter;
            //cout << "find_letter: " << find_letter << endl;

            rr << text_word[letter];
            rr >> text_letter;

            //cout << "text_letter: " << text_letter << endl;


            // loop over all keys in mistakeDict
            for (auto &letter_in_map : mistakeDict)
            {
                foundLetter = false;
                // if found key == text_letter
                if (letter_in_map.first == find_letter)
                {   
                    //cout<<"key found: " <<letter_in_map.first<<endl;
                    // check if key values contain letter = text_letter
                    //cout<<"letter_in_map.second.size(); "<<letter_in_map.second.size()<<endl;
                    for (size_t i = 0; i < letter_in_map.second.size(); i++)
                    {
                        if(letter_in_map.second[i] == text_letter)
                        {
                            find_word[letter] = text_word[letter];
                            break;
                        }
                    }
                }
            }
        }
    }
    return find_word;
}

string phonetic::find(string text, string word)
{
    // splitting the text by: " "
    vector<string> text_dict = spaceSplitter(text);

    // map of key, vec<val> of any mistake possible
    std::map<std::string, vector<std::string>> mistakes = mistakesDictionary();

    for (auto i = text_dict.begin(); i != text_dict.end(); i++)
    {

        string curr_word = *i;
        // check if two words got similar length
        //cout<<"curr_word: "<<curr_word<<endl;
        //cout<<"word: "<<word<<" curr_word: "<<curr_word<<endl;
        //cout<<"word: "<< word<<" word.length: "<<word.length()<<endl;
        //cout<<"curr_word: "<< curr_word<<" curr_word.length: "<<curr_word.length()<<endl;
        if (word.length() == curr_word.length())
        {      
            // check if two words are similar
            if (word.compare(curr_word) == 0)
            {
                
                return word;
            }
                
            else
            {
                
                if(isSimilarWord(curr_word, word) == curr_word) return curr_word;
            }
        }
    }
    throw std::exception();
}

// int main()
// {
    
//       cout<<phonetic::find("check for correct words", "check")<<endl;;  

    

//     return 0;
// }