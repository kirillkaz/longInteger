#include "../Include/bigInt.h"
#include "../../logger/logFactory/logger.h"

bool bigInt::checkCorrect(std::string stroke) {
    if (stroke == "") return false;
    else {
        char whiteList[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

        //сравниваю каждый символ строки с каждым символом из белого списка
        for (int i = 0; i < stroke.length(); i++) {
            bool isCorrect = false;
            for (int j = 0; j < 10; isCorrect == true ? j += 10 : j++) {
                if (stroke[i] == whiteList[j]) isCorrect = true;
                else if ((i == 0) && stroke[0] == '-') isCorrect = true;
            }

            if (isCorrect == false) return false;
        }

        return true;
    }
}

bigInt::bigInt(std::string num){
    this->num = num;
}

bigInt& bigInt::operator+(bigInt a){
    //проверка на корректность
    if (checkCorrect(this->num) == false){
        logger* logFactory = new logger();
        Ilogger* log = logFactory->create();

        if(this->num == ""){
            log->logWarning("Вы ввели пустую строку. Числу автоматически было присвоено значение 0.");
            this->num = "0";
        }
        else log->logError("Недопустимый формат числа " + this->num);


        if (checkCorrect(a.num) == false){

            if(a.num == ""){
                log->logWarning("Вы ввели пустую строку. Числу автоматически было присвоено значение 0.");
                this->num = "0";
            }
            else log->logError("Недопустимый формат числа " + a.num);

            this->num = "0";
            return *this;
        }
        *this = a;
        return *this;
    }
    //конец проверки на корректность

    else {

        int remember = 0;
        //если второе число больше чем первое, то меняю их местами(чтобы не делать 2 отдельные реализации)
        bool isNeg = false;

        //проверка чисел на отрицательность
        if (this->num[0] == '-' && a.num[0] == '-') {
            isNeg = true;
            a.num = a.num.substr(1, a.num.length() - 1);
            this->num = this->num.substr(1, this->num.length() - 1);
        }

        else if (this->num[0] == '-') {
            this->num = this->num.substr(1, this->num.length() - 1);
            *this = a - *this;
            return *this;
        }

        else if (a.num[0] == '-') {
            a.num = a.num.substr(1, a.num.length() - 1);
            return (*this - a);
        }
        //закончили проверку на отрицательность

        if (this->num.length() < a.num.length()) {
            bigInt tmp = *this;
            *this = a;
            a = tmp;
        }
        int secNumIndex = this->num.length() - 1;
        int res = 0;
        char numForPaste;

        for (int i = a.num.length() - 1; i >= 0; i--) {
            //расчет суммы 2х чисел, которые стоят друг напротив друга присложении в столбик
            res = (int) (this->num[secNumIndex]) - 48 + (int) (a.num[i]) - 48 + remember;

            //единицы этого числа запилываю в итоговое число
            numForPaste = std::to_string(res % 10)[0];
            this->num[secNumIndex] = numForPaste;

            //если сумма больше 9, то запоминаю сколько десятков вышло в итоге, чтобы потом прибавить к сумме
            if (res > 9) remember = res / 10;
            else remember = 0;

            secNumIndex -= 1;
        }
        //если у меня что то запомнилось в remember, то прибавляю его к следующему элементу итогового числа
        if (secNumIndex > 0) {
            while (secNumIndex != -1 && remember != 0) {
                res = (int) (this->num[secNumIndex]) - 48 + remember;
                numForPaste = std::to_string(res % 10)[0];
                remember = res/ 10;
                this->num[secNumIndex] = numForPaste;
                secNumIndex -= 1;
            }
            if (remember == 1){
                this->num = std::to_string(remember) + this->num;
                remember--;
            }
        }
        else if (remember == 1) {
            if (this->num.length() == a.num.length()) this->num = std::to_string(remember) + this->num;
            else this->num[0] = std::to_string(remember + (int) this->num[0] - 48)[0];
        }

        if (isNeg == true) this->num = '-' + this->num;
        return *this;
    }
}
bigInt& bigInt::operator+=(bigInt a){
    return *this + a;
}

bigInt& bigInt::operator-(bigInt a){
    //проверка на корректность
    if (checkCorrect(this->num) == false){
        logger* logFactory = new logger();
        Ilogger* log = logFactory->create();

        if(this->num == ""){
            log->logWarning("Вы ввели пустую строку. Числу автоматически было присвоено значение 0.");
            this->num = "0";
        }
        else log->logError("Недопустимый формат числа " + this->num);


        if (checkCorrect(a.num) == false){

            if(a.num == ""){
                log->logWarning("Вы ввели пустую строку. Числу автоматически было присвоено значение 0.");
                this->num = "0";
            }
            else log->logError("Недопустимый формат числа " + a.num);

            this->num = "0";
            return *this;
        }
        *this = a;
        return *this;
    }
    //конец проверки на корректность

    //если второе число больше чем первое, то меняю их местами(чтобы не делать 2 отдельные реализации
    //////////////////////////////////////////////////////
    bool isNeg = false;

    if (this->num[0] =='-' && a.num[0] =='-'){
        a.num = a.num.substr(1,a.num.length()-1);
        this->num = this->num.substr(1,this->num.length()-1);
        *this = a - *this;
        return *this;
    }
    else if (this->num[0] =='-'){
        a.num = '-' + a.num;
        return *this + a;
    }
    else if (a.num[0] =='-'){
        a.num = a.num.substr(1,a.num.length()-1);
        return *this + a;
    }

    if (this->num.length() < a.num.length()){
        bigInt tmp = *this;
        *this = a;
        a = tmp;
        isNeg = true;
    }

    else if(this->num.length() == a.num.length()){
        bool isSwap = false;
        int i = 0;
        while((this->num[i] >= a.num[i]) && (i != this->num.length())){
            i++;
        }
        if (this->num[i] < a.num[i]){
            bigInt tmp = *this;
            *this = a;
            a = tmp;
            isNeg = true;
        }
    }
    //////////////////////////////////////////////////////
    int thisIndex = this->num.length()-1;

    for(int i = a.num.length()-1;i>=0;i--){
        int res = 0;

        int numThis = (int)this->num[thisIndex]-48;
        int numA = (int)a.num[i]-48;

        //если единица большего числа меньше единицы нижнего числа, то занимаю десяток у более большого разряда
        if (numThis < numA){
            numThis+=10;
            numThis-=numA;
            this->num[thisIndex] = std::to_string(numThis)[0];
            //заменяюю следющий разряд большего числа(this) на число на единицу меньшее
            int minusIndex = 1;
            while (this->num[thisIndex-minusIndex] == '0') {
                //рассматриваю случай 10000000-1 (нули должны поменяться на девятки, а последнее число должно стать равным нулю)
                if (this->num[thisIndex-minusIndex] == '0') this->num[thisIndex - minusIndex] = '9';
                else this->num[thisIndex - minusIndex] = std::to_string((int) this->num[thisIndex - minusIndex] - 48 - 1)[0];
                minusIndex++;
            }
            this->num[thisIndex - minusIndex] = std::to_string((int) this->num[thisIndex - minusIndex] - 48 - 1)[0];
            if (this->num[0] == '0') {
                this->num = this->num.substr(1,this->num.length());
                thisIndex--;
            }
        }

        else{
            numThis-=numA;
            this->num[thisIndex] = std::to_string(numThis)[0];
        }
        thisIndex--;
    }
    //вайлом избавляюсь от всех нулей в начале
    while ((this->num[0] == '0') && (this->num.length() > 1)) this->num = this->num.substr(1,this->num.length()-1);
    if (isNeg == true) this->num = '-' + this->num;

    return *this;
}
bigInt& bigInt::operator-=(bigInt a){
    return *this - a;
}

bigInt& bigInt::operator*(bigInt a){
    //проверка на корректность
    if (checkCorrect(this->num) == false){
        logger* logFactory = new logger();
        Ilogger* log = logFactory->create();

        if(this->num == ""){
            log->logWarning("Вы ввели пустую строку. Числу автоматически было присвоено значение 0.");
            this->num = "0";
        }
        else log->logError("Недопустимый формат числа " + this->num);


        if (checkCorrect(a.num) == false){

            if(a.num == ""){
                log->logWarning("Вы ввели пустую строку. Числу автоматически было присвоено значение 0.");
                this->num = "0";
            }
            else log->logError("Недопустимый формат числа " + a.num);

            this->num = "0";
            return *this;
        }
        *this = a;
        return *this;
    }
    //конец проверки на корректность

    bool isNeg = false;
    //если второе число больше чем первое, то меняю их местами(чтобы не делать 2 отдельные реализации)
    if (this->num.length() < a.num.length()){
        bigInt tmp = *this;
        *this = a;
        a = tmp;
    }

    if (this->num[0] == '-'){
        isNeg = !isNeg;
        this->num = this->num.substr(1,this->num.length()-1);
    }
    if (a.num[0] == '-'){
        isNeg = !isNeg;
        a.num = a.num.substr(1,a.num.length()-1);
    }

    std::string zeroes = "";

    int thisIndex = this->num.length()-1;

    bigInt tmpMult;
    tmpMult.num = "0";
    bigInt result;
    result.num = "0";
    for (int i=a.num.length()-1;i>=0;i--){
        tmpMult.num = this->num;
        //переменная для запоминания десятков после умножения цифры на цифру
        int remember = 0;
        int B = (int)(a.num[i]-48);
        //умножаю число(разряд второго числа) на первое число(this)
        for (int j = thisIndex;j>=0;j--){
            int A = (int)(tmpMult.num[j]-48);

            if ((A * B + remember) > 9) tmpMult.num[j] = std::to_string(A * B + remember)[1];
            else tmpMult.num[j] = std::to_string(A * B + remember)[0];
            remember = (A * B + remember)/10;
        }
        if(remember > 0) tmpMult.num = std::to_string(remember) + tmpMult.num + zeroes;
        else tmpMult.num = tmpMult.num + zeroes;

        result = result + tmpMult;
        zeroes+="0";
    }

    *this = result;

    //вайлом избавляюсь от всех нулей в начале
    while ((this->num[0] == '0') && (this->num.length() > 1)) this->num = this->num.substr(1,this->num.length()-1);

    if (isNeg == true && this->num != "0") this->num = "-" + this->num;
    return *this;
}
bigInt& bigInt::operator*=(bigInt a){
    return *this * a;
}

std::ostream& operator<<(std::ostream& out, bigInt& num){
    out<< num.num;
    return out;
}

bigInt::~bigInt(){

}