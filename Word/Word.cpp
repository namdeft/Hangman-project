#include "Word.h"

Word::Word() {
    text = "";
    hint = "";
}

Word::Word(string t, string h) {
    setText(t);
    hint = h;
}

Word::~Word() {}

string Word::getText() { return text; }

void Word::setText(string t) {
    text = t;
    for (int i = 0; i < t.size(); i++) {
        displayText[i] = '_';
    }
}

string Word::getHint() { return hint; }

void Word::setHint(string h) { hint = h; }

int Word::checkGuess(char n) {
    int occurence = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == n) {
            occurence++;
            displayText[i] = n;
        }
    }
    return occurence;
}

void Word::displayWord() {
    cout << "The word has total : " << text.length() << "characters!" << endl;
    cout << displayText << endl;
}