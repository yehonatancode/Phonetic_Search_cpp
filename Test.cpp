#include "doctest.h"
#include "PhoneticFinder.hpp"

string text = "hawing ewery deliwered nov to today View predty wery ytself With motual su sais bacc sealously inkuietude guezt rijht Unknown Jokes doubtbul goy doubtpul bart bormed Boy Painful packajes ";

TEST_CASE("v,w"){  
    CHECK(phonetic::find(text, "having").compare("hawing") == 0);
    CHECK(phonetic::find(text, "every").compare("ewery") == 0);
    CHECK(phonetic::find(text, "delivered").compare("deliwered") == 0);
    CHECK(phonetic::find(text, "now").compare("nov") == 0);
    CHECK(phonetic::find(text, "view").compare("View") == 0);  
    CHECK(phonetic::find(text, "very").compare("wery") == 0); 
    CHECK(phonetic::find(text, "unknown").compare("Unknown") == 0);
}
TEST_CASE("b,f,p"){
    CHECK(phonetic::find(text, "doubtful").compare("doubtbul") == 0);
    CHECK(phonetic::find(text, "formed").compare("bormed") == 0);
    CHECK(phonetic::find(text, "boy").compare("Boy") == 0);
}
TEST_CASE("g,j"){
    CHECK(phonetic::find(text, "packages").compare("packajes") == 0);
    CHECK(phonetic::find(text, "joy").compare("goy") == 0);
    CHECK(phonetic::find(text, "right").compare("rijht") == 0);
    CHECK(phonetic::find(text, "jokes").compare("Jokes") == 0);
}
TEST_CASE("c, k, q"){
    CHECK(phonetic::find(text, "packages").compare("packajes") == 0);
    CHECK(phonetic::find(text, "inquietude").compare("inkuietude") == 0);
    CHECK(phonetic::find(text, "back").compare("bacc") == 0);
}

TEST_CASE("s, z"){
    CHECK(phonetic::find(text, "guest").compare("guezt") == 0);
    CHECK(phonetic::find(text, "zealously").compare("sealously") == 0); //19


}
TEST_CASE("d, t"){
    CHECK(phonetic::find(text, "do").compare("to") == 0);
    CHECK(phonetic::find(text, "with").compare("With") == 0);
}
TEST_CASE("o, u"){

    CHECK(phonetic::find(text, "so").compare("su") == 0);
    CHECK(phonetic::find(text, "mutual").compare("motual") == 0);

}
TEST_CASE("i, y"){

    CHECK(phonetic::find(text, "itself").compare("ytself") == 0);
    CHECK(phonetic::find(text, "says").compare("sais") == 0); 
}


TEST_CASE("random words"){
    CHECK(phonetic::find(text, "today").compare("today") == 0);
    CHECK(phonetic::find(text, "pretty").compare("predty") == 0);  //27

}


string text2 = "I vill, jo!.";

TEST_CASE("exception check"){
CHECK_THROWS_AS(phonetic::find(text2, "todfghgfhdgday"),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "villi"),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "g"),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "3"),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "25"),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "oi"),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, ""),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "jO"),std::exception);            
CHECK_THROWS_AS(phonetic::find(text2, ""),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, " "),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "."),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "!"),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, ","),std::exception);    
CHECK_THROWS_AS(phonetic::find(text2, "R"),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "V"),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "II"),std::exception);
CHECK_THROWS_AS(phonetic::find(text2, "  "),std::exception);        //44


}

string text3 = "check for correct words";
string text4 = "I will go To pOol";

TEST_CASE("check for correct words"){
    CHECK(phonetic::find(text3, "check").compare("check") == 0);
    CHECK(phonetic::find(text3, "for").compare("for") == 0);
    CHECK(phonetic::find(text3, "correct").compare("correct") == 0);
    CHECK(phonetic::find(text3, "words").compare("words") == 0);        
    
    CHECK(phonetic::find(text4, "I").compare("I") == 0);
    CHECK(phonetic::find(text4, "will").compare("will") == 0);
    CHECK(phonetic::find(text4, "go").compare("go") == 0);
    CHECK(phonetic::find(text4, "to").compare("To") == 0);
    CHECK(phonetic::find(text4, "pool").compare("pOol") == 0);      
}


string text5 = "I Will go To School fOr eaT caKe";

TEST_CASE("bit letter case"){
    CHECK(phonetic::find(text5, "i").compare("I") == 0);
    CHECK(phonetic::find(text5, "will").compare("Will") == 0);
    CHECK(phonetic::find(text5, "to").compare("To") == 0);
    CHECK(phonetic::find(text5, "school").compare("School") == 0);      
    CHECK(phonetic::find(text5, "for").compare("fOr") == 0);
    CHECK(phonetic::find(text5, "eat").compare("eaT") == 0);
    CHECK(phonetic::find(text5, "cake").compare("caKe") == 0);      
}


string text6 = "zoper zfurt ford pace vawe fluppy";

TEST_CASE("two wrong letter case"){
    CHECK(phonetic::find(text6, "sport").compare("zfurt") == 0);
    CHECK(phonetic::find(text6, "port").compare("ford") == 0);
    CHECK(phonetic::find(text6, "fake").compare("pace") == 0);
    CHECK(phonetic::find(text6, "sport").compare("zfurt") == 0);
    CHECK(phonetic::find(text6, "wave").compare("vawe") == 0);      
    CHECK(phonetic::find(text6, "fluffy").compare("fluppy") == 0);  //66
}

string text7 = "vork cnow drue uut ies jame peel qake soo tone";

TEST_CASE("firt letter wrong"){
    CHECK(phonetic::find(text7, "work").compare("vork") == 0);
    CHECK(phonetic::find(text7, "know").compare("cnow") == 0);
    CHECK(phonetic::find(text7, "true").compare("drue") == 0);
    CHECK(phonetic::find(text7, "out").compare("uut") == 0);
    CHECK(phonetic::find(text7, "yes").compare("ies") == 0);
    CHECK(phonetic::find(text7, "game").compare("jame") == 0);
    CHECK(phonetic::find(text7, "feel").compare("peel") == 0);
    CHECK(phonetic::find(text7, "cake").compare("qake") == 0);      
    CHECK(phonetic::find(text7, "zoo").compare("soo") == 0);
    CHECK(phonetic::find(text7, "done").compare("tone") == 0);      //76
}


string text8 = "speet peec plai prew crof gaj rag fuzs dasz pud su pu hy";

TEST_CASE("last letter wrong "){
    CHECK(phonetic::find(text8, "speed").compare("speet") == 0);
    CHECK(phonetic::find(text8, "peek").compare("peec") == 0);
    CHECK(phonetic::find(text8, "play").compare("plai") == 0);
    CHECK(phonetic::find(text8, "prev").compare("prew") == 0);
    CHECK(phonetic::find(text8, "crop").compare("crof") == 0);        
    CHECK(phonetic::find(text8, "gag").compare("gaj") == 0);
    CHECK(phonetic::find(text8, "raj").compare("rag") == 0);        
    CHECK(phonetic::find(text8, "fuzz").compare("fuzs") == 0);
    CHECK(phonetic::find(text8, "dazz").compare("dasz") == 0);
    CHECK(phonetic::find(text8, "put").compare("pud") == 0);
    CHECK(phonetic::find(text8, "po").compare("pu") == 0);
    CHECK(phonetic::find(text8, "hi").compare("hy") == 0);      //88

}

string text9 = "splidder rewwork guugle cokkaine cappeine bajjuete pazzed pissa cotter dayyer paiier cluBBer";
TEST_CASE("double wrong letters"){
    CHECK(phonetic::find(text9, "splitter").compare("splidder") == 0);
    CHECK(phonetic::find(text9, "revvork").compare("rewwork") == 0);
    CHECK(phonetic::find(text9, "google").compare("guugle") == 0);
    CHECK(phonetic::find(text9, "coccaine").compare("cokkaine") == 0);
    CHECK(phonetic::find(text9, "caffeine").compare("cappeine") == 0);      
    CHECK(phonetic::find(text9, "bagguete").compare("bajjuete") == 0);
    CHECK(phonetic::find(text9, "passed").compare("pazzed") == 0);
    CHECK(phonetic::find(text9, "pizza").compare("pissa") == 0);                
    CHECK(phonetic::find(text9, "codder").compare("cotter") == 0);
    CHECK(phonetic::find(text9, "daiier").compare("dayyer") == 0);              
    CHECK(phonetic::find(text9, "payyer").compare("paiier") == 0);              
    CHECK(phonetic::find(text9, "clubber").compare("cluBBer") == 0);            //100

}

string text10 = "Vw BfP";
string text11 = "abcdefghijklmnopqrstuvwxyz";
string text12 = "abcdefghijklmnopq";
string text13 = "Vw B";

TEST_CASE("ofek test"){
    CHECK(phonetic::find(text10, "wv").compare("Vw") == 0);
    CHECK(phonetic::find(text11, "ABcDEFGHIJKLMNOPQRSTUVWXYZ").compare("abcdefghijklmnopqrstuvwxyz") == 0); 
    CHECK(phonetic::find(text12, "ABCDEFGHIJKLMNOPQ").compare("abcdefghijklmnopq")==0); 
    CHECK( phonetic::find(text10, "PPf") == string("BfP"));
    CHECK( phonetic::find(text13, "P") == string("B"));
}