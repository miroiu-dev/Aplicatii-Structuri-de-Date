

#include <iostream>
#include <set>

struct letter {
    char letter;
    int power;
};

struct ListNode {
    int value;
    letter Letter;
    ListNode* next;
};



void createList(ListNode* Polinom) {
    int lengthOfPolinom;
    std::cout << "Cate variabile vrei sa introduci in Polinom?" << std::endl;
    std::cin >> lengthOfPolinom;

    while (lengthOfPolinom--) {
        Polinom->next = new ListNode;
        std::cout << "Numarul : ";
        std::cin >> Polinom->next->value;
        std::cout << "Litera : ";
        std::cin >> Polinom->next->Letter.letter;
        std::cout << "Puterea : ";
        std::cin >> Polinom->next->Letter.power;
        Polinom = Polinom->next;
    }

    Polinom->next = nullptr;


}

void finishPolinom(ListNode* Polinom, ListNode*& result) {
    while (Polinom) {
        result->next = new ListNode;
        result->next = Polinom;
        result = result->next;

        Polinom = Polinom->next;
    }
}

void inserateNode(ListNode*& Polinom, ListNode*& result) {
    result->next = new ListNode;
    result->next = Polinom;
    result = result->next;

    Polinom = Polinom->next;
}

ListNode* sumList(ListNode* firstPolinom, ListNode* secondPolinom) {

    ListNode* resultPolinom = new ListNode;
    ListNode* secondResultPolinom = resultPolinom;

    while (firstPolinom && secondPolinom) {
        if (firstPolinom->Letter.power == secondPolinom->Letter.power) {
            secondResultPolinom->next = new ListNode;
            secondResultPolinom->next->value = firstPolinom->value + secondPolinom->value;
            secondResultPolinom->next->Letter = firstPolinom->Letter;
            secondResultPolinom = secondResultPolinom->next;

            firstPolinom = firstPolinom->next;
            secondPolinom = secondPolinom->next;
        }
        else if (firstPolinom->Letter.power > secondPolinom->Letter.power)
            inserateNode(firstPolinom, secondResultPolinom);
        else
            inserateNode(secondPolinom, secondResultPolinom);
    }

    finishPolinom(firstPolinom, secondResultPolinom);
    finishPolinom(secondPolinom, secondResultPolinom);

    secondResultPolinom = nullptr;
    return resultPolinom->next;
}

void Dinamic() {

    ListNode* firstPolinom = new ListNode, * secondPolinom = new ListNode;
    createList(firstPolinom);
    createList(secondPolinom);
    firstPolinom = firstPolinom->next, secondPolinom = secondPolinom->next;

    ListNode* result = sumList(firstPolinom, secondPolinom);

    while (result) {
        std::cout << result->value << result->Letter.letter << result->Letter.power << '+' << std::endl;
        result = result->next;
    }
}

int main()
{
    Dinamic();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
