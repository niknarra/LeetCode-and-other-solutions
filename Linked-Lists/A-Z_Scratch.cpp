#include <iostream>
using namespace std;

class Node{
public:

    int val;
    Node* next;

    Node(int newVal, Node* newNext = nullptr){
        val = newVal;
        next = newNext;
    }

};

void listPrinter(Node* head){
    if(head == nullptr) return;

    Node* curr = head;
    cout<<"Nodes: ";

    while(curr != nullptr){
        cout<<curr->val<<" ";
        curr = curr->next;
    }
}

void reversePrinter(Node* head){
    if(head == nullptr) return;

    reversePrinter(head->next);
    cout<<head->val<<" ";

}

Node* listReverser(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* curr = head;
    Node* prev = nullptr;

    while(curr!=nullptr){
        Node* front = curr->next;

        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

int listLength(Node* head){
    if(head == nullptr) return 0;

    int ans = 0;

    Node* curr = head;

    while(curr != nullptr){
        curr = curr->next;
        ans += 1;
    }
    return ans;
}

int listLengthRecursive(Node* head) {
    if (head == nullptr) return 0;

    return 1 + listLengthRecursive(head->next);
}

Node* listSearcher(Node* head, int target){
    if (head == nullptr || head->val == target) return head;

    Node* curr = head;

    while(curr != nullptr){
        if(curr->val == target) return curr;

        curr = curr->next;
    }
    return nullptr;
}

Node* listSearcherRecursive(Node* head, int target){
    if (head == nullptr || head->val == target) return head;

    return listSearcherRecursive(head->next, target);
}

Node* nodeAdder(Node* head, Node* target, int pos){
    //At Head
    target->next = head;
    return target;

    //At Tail
    Node* curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = target;
    return head;

    //At Pos
    int curr_pos = 1;
    Node* curr = head;

    while(curr != nullptr){
        if (curr_pos == pos){
            Node* front = curr->next;
            curr->next = target;
            target->next = front;

            return head;
        }
        curr_pos += 1;
        curr = curr->next;
    }
}

Node* nodeRemover(Node* head, Node* target, int pos){
    //At Head
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;

    //At Tail
    Node* curr = head;
    Node* newTail = nullptr;
    while(curr->next != nullptr){
        newTail = curr;
        curr = curr->next;
    }
    newTail->next = nullptr;
    delete curr;
    return head;

    //At pos
    Node* curr = head;
    Node* prev = nullptr;
    int curr_pos = 1;

    while(curr != nullptr){
        if (curr_pos == pos){
            Node* front = curr->next;
            prev->next = front;

            delete curr;
            return head;
        }
        prev = curr;
        curr_pos += 1;
        curr = curr->next;
    }

}

Node* getMiddle(Node* head){
    if(head == nullptr) return head;

    Node* hare = head;
    Node* tortoise = head;

    while(hare != nullptr && hare->next != nullptr){
        hare = hare->next->next;
        tortoise = tortoise->next;
    }

    return tortoise;
}

bool cycleDetector(Node* head){
    if(head == nullptr) return false;

    Node* hare = head;
    Node* tortoise = head;

    while(hare != nullptr && hare->next != nullptr){

        hare = hare->next->next;
        tortoise = tortoise->next;

        if(hare == tortoise){
            return true;
        }
    }
    return false;
}

Node* cycleStarter(Node* head){
    if(head == nullptr) return head;

    Node* hare = head;
    Node* tortoise = head;

    while(hare != nullptr && hare->next != nullptr){

        hare = hare->next->next;
        tortoise = tortoise->next;

        if(hare == tortoise){
            hare = head;

            while(hare != tortoise){
                tortoise = tortoise->next;
                hare = hare->next;
            }
            return hare;
        }
    }
    return nullptr;
}

int cycleLength(Node* head){
    if(head == nullptr) return 0;

    Node* hare = head;
    Node* tortoise = head;
    int count = 0;

    while(hare != nullptr && hare->next != nullptr){
        hare = hare->next->next;
        tortoise = tortoise->next;

        if(hare == tortoise){
            count = 1;
            hare = hare->next;

            while(hare!=tortoise){
                hare = hare->next;
                count += 1;
            }
            return count;
        }
    }

    return count;
}

bool isPalindrome(Node* head){
    if(head == nullptr || head->next == nullptr) return true;

    Node* curr_start = head;

    Node* middle = getMiddle(head);
    Node* curr_end = listReverser(middle);

    while(curr_end != nullptr){
        if(curr_start->val != curr_end->val) return false;

        curr_start = curr_start->next;
        curr_end = curr_end->next;
    }
    return true;
}

Node* listMerger(Node* p, Node* q){
    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;

    Node* curr_p = p;
    Node* curr_q = q;

    while(curr_p != nullptr && curr_q != nullptr){
        if(curr_p->val < curr_q->val){
            Node* temp = new Node(curr_p->val);
            curr->next = temp;
            curr = curr->next;
            curr_p = curr_p->next;
        }
        else if(curr_p->val > curr_q->val){
            Node* temp = new Node(curr_q->val);
            curr->next = temp;
            curr = curr->next;
            curr_q = curr_q->next;
        }
        else{
            Node* temp = new Node(curr_q->val);
            curr->next = temp;
            curr = curr->next;
            curr->next = temp;
            curr = curr->next;
            curr_p = curr_p->next;
            curr_q = curr_q->next;
        }
    }
    if(curr_p) curr->next = curr_p;

    if(curr_q) curr->next = curr_q;

    return dummyHead->next;
}

Node* listSorter(Node* head){
    if(head == nullptr || head->next == nullptr) return head;

    Node* middle = getMiddle(head);
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    Node* leftHalf = listSorter(left);
    Node* rightHalf = listSorter(right);

    return listMerger(leftHalf, rightHalf);
}

Node* middleDelete(Node* head){
    if(head == nullptr) return head;

    Node* middle = getMiddle(head);
    Node* curr = head;

    while(curr->next != middle){
        curr = curr->next;
    }

    curr->next = middle->next;
    delete middle;
    return head;
}

Node* sort012(Node* head){
    if(head == nullptr || head->next == nullptr) return head;

    Node* curr = head;

    Node* list0 = new Node(-1);
    Node* temp0 = list0;

    Node* list1 = new Node(-1);
    Node* temp1 = list1;

    Node* list2 = new Node(-1);
    Node* temp2 = list2;

    while(curr != nullptr){
        if(curr->val == 0){
            temp0->next = curr;
            temp0 = temp0->next;
        }
        else if (curr->val == 1) {
            temp1->next = curr;
            temp1 = temp1->next;
        }
        else{
            temp2->next = curr;
            temp2 = temp2->next;
        }
        curr = curr->next;
    }

    temp0->next = (list1->next != nullptr) ? list1->next : list2->next;
    temp1->next = list2->next;
    temp2->next = nullptr;

    return list0->next;
}

Node* addTwoNumbers(Node* p, Node* q){
    if(p == nullptr && q == nullptr) return nullptr;

    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;

    Node* curr_p = listReverser(p);
    Node* curr_q = listReverser(q);
    int carry = 0;

    while(curr_p != nullptr || curr_q != nullptr || carry != 0){
        int digit1 = curr_p != nullptr ? curr_p->val : 0;
        int digit2 = curr_q != nullptr ? curr_q->val : 0;

        int curr_sum = digit2 + digit1 + carry;
        int digit = curr_sum % 10;
        carry = curr_sum / 10;

        Node* temp = new Node(digit);
        curr->next = temp;
        curr = curr->next;

        if(curr_p) curr_p = curr_p->next;
        if(curr_q) curr_q = curr_q->next;
    }

    return listReverser(dummyHead->next);
}

Node* addOne(Node* head){
    if (head == nullptr) return new Node(1);
    int carry = 1;

    Node* dummyHead = new Node(-1);
    Node* curr_rev = dummyHead;

    Node* reversed = listReverser(head);
    Node* curr = reversed;

    while(curr != nullptr && carry != 0){
        int curr_digit = curr->val;
        int sum = curr_digit+carry;

        carry = sum / 10;
        int digit = sum % 10;

        Node* temp = new Node(digit);
        curr_rev->next = temp;
        curr_rev = curr_rev->next;

        curr = curr->next;

    }

    if(carry == 1){
        curr_rev->next = new Node(1);
    }

    Node* res = listReverser(dummyHead->next);
    return res;
}



int main() {
    cout << "Linked Lists"<<endl;

    Node* head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(7);
    head->next->next->next = new Node(11);

    // Node* reversed = listReverser(head);
    // listPrinter(reversed);

    int n = listLength(head);
    cout<<n;

    return 0;
}
