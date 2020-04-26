学会使用sort解决简单排序

如果出现超时并且没有较好的优化思路，直接尝试修改所有`cout`为`printf`, 若还是不行再尝试修改`cin`为`scanf`，如果仍旧超时可以暂时跳过检查点

```c++
//Student List for Course

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void print(vector<vector<string>> &totalCourse);
int main(){
    int stuNum;
    int courseNum;
    string name;
    int courseID;
    int stuCourseNum;
    cin >> stuNum >> courseNum;
    vector<string> singleCourse;
    vector<vector<string>> totalCourse;
    totalCourse.resize(courseNum);
    for (int i = 0; i < stuNum; i++){
        // solve n students
        cin>>name;
        cin>>stuCourseNum;
        for (int k = 0 ; k<stuCourseNum; k++){
            cin >> courseID;
            totalCourse[courseID-1].push_back(name);
        }
    }
    print(totalCourse);
    return 0;
}

void print(vector<vector<string>> &totalCourse){
    for (int i = 0 ;i <totalCourse.size();i++){
            printf("%d %d\n",i+1,totalCourse[i].size());
            sort(totalCourse[i].begin(), totalCourse[i].end());
        for (int k = 0; k < totalCourse[i].size(); k++){
            printf("%s\n", totalCourse[i][k].c_str());
        }
    }
}

```

