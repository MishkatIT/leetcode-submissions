class Solution {
public:
    
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i = 0;
        string temp = "";
        while (num) {
            if (num % 1000 != 0) {
                temp = func(num % 1000) + thousands[i] + " " + temp;
            }
            num /= 1000;
            i++;
        }
        
        while (temp.back() == ' ') {
            temp.pop_back();
        }
        
        return temp;
    }
    
    vector<string> belowTwenty{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                               "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
                               "Eighteen", "Nineteen"};
    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands{"", "Thousand", "Million", "Billion"};

    string func(int num) {
        if (num == 0) return "";
        else if (num < 20) return belowTwenty[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + func(num % 10);
        else return belowTwenty[num / 100] + " Hundred " + func(num % 100);
    }
};