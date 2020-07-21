#include<iostream>
#include<string>

using namespace std;

int hexTransfer(char a) {
    if (a >= '0' && a <= '9') {
        return a - '0';
    }
    else if (a >= 'a' && a <= 'f') {
        return a - 87;
    }
    else {
        return a - 65;
    }
}

int transHexFormaet(string a) {
    int ans = 0;
    int size = a.length() - 1;
    for (int i = 2; i < size; i++) {
        ans = ans * 16 + hexTransfer(a[i]);
    }
    return ans;
}


int main() {

    ios::sync_with_stdio(false);

    char signal;
    string target;
    char jhljx[] = "jhljx";
    char xihang[] = "xihang";

    while (cin >> signal) {
        cin >> target;

        if (signal == 'A') {
            int size = target.length();
            for (int i = 0; i < size; i += 8) {
                char a = (char)(hexTransfer(target[i]) * 128 +
                    hexTransfer(target[i + 1]) * 64 +
                    hexTransfer(target[i + 2]) * 32 +
                    hexTransfer(target[i + 3]) * 16 +
                    hexTransfer(target[i + 4]) * 8 +
                    hexTransfer(target[i + 5]) * 4 +
                    hexTransfer(target[i + 6]) * 2 +
                    hexTransfer(target[i + 7]) * 1);
                cout << a;
            }
            cout << endl;
        }
        else {
            bool found = false;//found XY

            for (int i = 0; i < target.length(); ++i) {

                int state = 0;//状态自动机

                if (target[i] != 'j' && target[i] != 'x') {
                    continue;
                }

                int j = 0;
                int x = i;//记录当前下标
                int temp;

                if (target[i] == 'j') {

                    while (target[x++] == jhljx[j++] && jhljx[j] != '\0' && x < target.length());
                    //读取到最后成功，或者原数组长度不够，或者不等的失败，都会终止识别

                    if (jhljx[j] == '\0') {
                        //成功得读到了最后

                        state = 1;//状态变为jhljx
                        temp = x;

                    }
                    j = 0;
                    x--;
                    //回撤一个单位，开始处理jhljxihang的问题
                    //cout << "now x is " << x << endl;
                    while (target[x++] == xihang[j++] && xihang[j] != '\0' && x < target.length());

                    if (xihang[j] == '\0') {
                        state = 2;//此时的状态应该变成xihang了
                        temp = x;
                    }

                }
                else {
                    while (target[x++] == xihang[j++] && xihang[j] != '\0' && x < target.length());

                    if (xihang[j] == '\0') {
                        state = 2;
                        temp = x;
                    }
                }

                if (state) {

                    i = temp;//跳过所有名字相关的字符

                    while (i < target.length() && !(target[i] == 'x' && target[i - 1] == '0')) {
                        i++;
                    }
                    //找0x，无论成功还是越界失败都会停止
                    int result = 0;
                    int resultx, resulty;

                    for (i++; i < target.length() && target[i] != '#'; ++i) {

                        if ((target[i] >= '0' && target[i] <= '9') ||
                            (target[i] >= 'a' && target[i] <= 'f' ||
                            (target[i] >= 'A' && target[i] <= 'F')))
                        {
                            result = result * 16 + hexTransfer(target[i]);
                        }
                        else {
                            break;
                        }

                    }
                    //cout << "i is :" << i << " length : " << target.length() << endl;
                    if (i >= target.length())
                    {
                        break;
                    }

                    else
                    {
                        resultx = result;
                        while (i < target.length() && !(target[i] == 'x' && target[i - 1] == '0')) {
                            i++;
                        }
                        result = 0;

                        for (i++; i < target.length() && target[i] != '#'; ++i) {

                            if ((target[i] >= '0' && target[i] <= '9') ||
                                (target[i] >= 'a' && target[i] <= 'f' ||
                                (target[i] >= 'A' && target[i] <= 'F')))
                            {
                                result = result * 16 + hexTransfer(target[i]);
                            }
                            else {
                                break;
                            }

                        }
                        //cout << "i is :" << i << " length : " << target.length() << endl;
                        if (i >= target.length())
                        {
                            break;
                        }

                        
                        resulty = result;
                        if (state == 1) {
                            cout << "jhljx(" << resultx << "," << resulty << ")" << " ";
                        }
                        else {
                            cout << "xihang(" << resultx << "," << resulty << ")" << " ";
                        }
                        state = 0;
                        found = true;
                    }

                }

            }
            if (!found) {
                cout << "nothing found!" << endl;
            }
            else {
                cout << endl;
            }

        }

    }
    return 0;

}
