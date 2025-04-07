class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;  // 空输入直接返回空结果
        string path;                       // 存储当前组合的临时字符串
        backtrack(digits, 0, path, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& path, vector<string>& result) {
        // 电话号码映射表（静态变量，避免重复创建）
        static const vector<string> phoneMap = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"  // 索引对应数字 0-9
        };

        if (index == digits.size()) {       // 递归终止条件[9,10](@ref)
            result.push_back(path);         // 将当前组合加入结果集
            return;
        }

        char num = digits[index];           // 当前处理的数字字符（如 '2'）
        string letters = phoneMap[num - '0'];// 获取对应字母集合（如 '2' → "abc"）

        for (char c : letters) {            // 遍历所有可能的字母[1,9](@ref)
            path.push_back(c);              // 添加当前字母到组合
            backtrack(digits, index + 1, path, result); // 递归处理下一位数字
            path.pop_back();                // 回溯，移除当前字母尝试下一个选项
        }
    }
};

