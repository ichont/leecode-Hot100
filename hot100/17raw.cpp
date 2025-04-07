class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;  // ������ֱ�ӷ��ؿս��
        string path;                       // �洢��ǰ��ϵ���ʱ�ַ���
        backtrack(digits, 0, path, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& path, vector<string>& result) {
        // �绰����ӳ�����̬�����������ظ�������
        static const vector<string> phoneMap = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"  // ������Ӧ���� 0-9
        };

        if (index == digits.size()) {       // �ݹ���ֹ����[9,10](@ref)
            result.push_back(path);         // ����ǰ��ϼ�������
            return;
        }

        char num = digits[index];           // ��ǰ����������ַ����� '2'��
        string letters = phoneMap[num - '0'];// ��ȡ��Ӧ��ĸ���ϣ��� '2' �� "abc"��

        for (char c : letters) {            // �������п��ܵ���ĸ[1,9](@ref)
            path.push_back(c);              // ��ӵ�ǰ��ĸ�����
            backtrack(digits, index + 1, path, result); // �ݹ鴦����һλ����
            path.pop_back();                // ���ݣ��Ƴ���ǰ��ĸ������һ��ѡ��
        }
    }
};

