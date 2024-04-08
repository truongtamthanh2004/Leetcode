class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0;
        while (count < students.size())
        {
            if (students[0] != sandwiches[0])
            {
                int tmp = students[0];
                students.erase(students.begin());
                students.push_back(tmp);
                count++;
            }
            else
            {
                count = 0;
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
            }
        }
        return students.size();
    }
};