#include<iostream>
#include<vector>
#include<string>
#include"class.h"
using namespace std;

int main() {

	//���ֲ����㷨
	solution a;
	vector<int> sort_array = { 1,2,5,8,14,67 };
	int target = 7;
	cout << a.binary_search1(sort_array, target) << endl;
	cout << a.binary_search2(sort_array, 0, 5, target) << endl;
	cout << a.searchInsert(sort_array, target) << endl;

	vector<int> sort_array2 = { 1,2,2,2,3,3,4,5,9,9 };
	vector<int> result;
	result = a.searchRange(sort_array2, 2);
	cout << "[" << result[0] << "," << result[1] << "]" << endl;

	//5.��ת�������
	vector<int> sort_array3 = { 5,7,9,17,1,2,3 };
	cout << "��5�⣺" << a.search(sort_array3, 2) << endl;

	//6.����������Ĳ���
	/*
	*             8
	*         3       10
	*	    1   6         15
	*/
	cout << endl<<"6:-------------------����������Ĳ���----------------------:6" << endl;
	vector<TreeNode*> node_vec;
	vector<int> test = { 3,10,1,6,15 };
	TreeNode root(8);
	for (int i = 0; i < 5; i++) {
		node_vec.push_back(new TreeNode(test[i]));
	}
	for (int i = 0; i < 5; i++) {
		a.BST_insert(&root, node_vec[i]);
	}
	cout << "left val of root:" << root.left->val << "  right val of root:" << root.right->val << endl;
	for (int i = 0; i < 5; i++) {
		/*cout << "left val of " << node_vec[i]->val << ":" << node_vec[i]->left->val <<
			"  right val of " << node_vec[i]->val << ":" << node_vec[i]->right->val << endl;;
		*/
		cout << node_vec[i]->val << endl;;
	}
	cout << "6:-------------------����������Ĳ���----------------------:6" << endl;
	cout << endl;

	//7.���������������
	cout << "7:-------------------���������������----------------------:7" << endl;

	cout<<a.BST_search(&root, 11)<<endl;

	cout << "7:-------------------���������������----------------------:7" << endl;
	cout << endl;

	/*8.���ַ�������ת��Ϊ���֡����磺str:"12345",int:12345*/
	cout << "8:-------------------�ַ����ִ�ת��Ϊ����----------------------:8" << endl;
	string str = "2345";
	cout << a.str_to_int(str) << endl;
	cout << "8:-------------------�ַ����ִ�ת��Ϊ����----------------------:8" << endl;
	cout << endl;


	/*9 ���л��ͷ����л�����������*/
	cout << "9:-------------------���л��ͷ����л�����������----------------------:9" << endl;
	cout<<a.serialize(&root)<<endl;
	cout << "9:-------------------���л��ͷ����л�����������----------------------:9" << endl;
	cout << endl;

	/*10 �����Ҳ�С�ڵ�ǰԪ�صĸ���,���磺���룺nums = [5,2,6,1] �����[2,1,1,0]*/
	cout << "10:-------------------�����Ҳ�С�ڵ�ǰԪ�صĸ���----------------------:10" << endl;
	vector<int> nums10;
	nums10.push_back(5);
	nums10.push_back(2);
	nums10.push_back(6);
	nums10.push_back(1);
	for (int i = 0; i < 4; i++) {
		cout << a.countSmaller(nums10)[i] << endl;
	}
	cout << "10:-------------------�����Ҳ�С�ڵ�ǰԪ�صĸ���----------------------:10" << endl;
	cout << endl;
	return 0;
}