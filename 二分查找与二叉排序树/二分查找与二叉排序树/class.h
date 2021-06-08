#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int num):val(num),left(NULL),right(NULL){}
};
struct BSTNode {
	int val;
	int count;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int x) :val(x), count(0), left(NULL), right(NULL) {}
};

class solution {
public:
	//1.����ѭ��ʵ�ֶ��ֲ���
	bool binary_search1(vector<int>& sort_array, int target);
	//2.���õݹ�ʵ�ֶ��ֲ���
	bool binary_search2(vector<int>& sort_array, int begin, int end, int target);

	/*3.����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
		���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
		����Լ������������ظ�Ԫ�ء�*/
	int searchInsert(vector<int>& nums, int target);

	/*4.����һ�������������е��������� nums����һ��Ŀ��ֵ target��
		�ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
		��������в�����Ŀ��ֵ target������ [-1, -1]��*/
	//4.1 Ѱ����˵�
	int left_bound(vector<int>& nums, int target);
	//4.2 Ѱ���Ҷ˵�
	int right_bound(vector<int>& nums, int target);
	
	vector<int> searchRange(vector<int>& nums, int target);

	/*5.�������� nums ���������У������е�ֵ ������ͬ ��
		�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ�������ת��
		ʹ�����Ϊ [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]���±� �� 0 ��ʼ ��������
		���磬 [0,1,2,4,5,6,7] ���±� 3 ������ת����ܱ�Ϊ [4,5,6,7,0,1,2] ��
		���� ��ת�� ������ nums ��һ������ target ����� nums �д������Ŀ��ֵ target ��
		�򷵻������±꣬���򷵻� -1 ��*/
	int search(vector<int>& nums, int target);

	/*6.����������Ĳ���ʵ��*/
	void BST_insert(TreeNode* node, TreeNode* insert_node);

	/*7.����������������*/
	bool BST_search(TreeNode* node, int value);

	/*8.���ַ�������ת��Ϊ���֡����磺str:"12345",int:12345*/
	int pow_int(int a, int b);
	int str_to_int(string& str);

	/*9 ���л��ͷ����л�����������*/
	/*9.1������ת��Ϊ�ַ���#����ʽ�����磺int��1234 -> string:"1234#"*/
	void change_int_to_string(int val, string& str_val);
	/*9.2 ���������������ǰ������ķ�ʽ��ת��Ϊ�ַ���������֮��ʹ��#����*/
	void BST_preorder(TreeNode* node, string& data);
	string serialize(TreeNode* root);
	TreeNode* deserialize(string data);

	/*10.����һ���������� nums����Ҫ�󷵻�һ�������� counts��
		 ���� counts �и����ʣ� counts[i] ��ֵ��  nums[i] �Ҳ�С�� nums[i] ��Ԫ�ص�������
		ʾ����
		���룺nums = [5,2,6,1]
		�����[2,1,1,0] 
		���ͣ�
		5 ���Ҳ��� 2 ����С��Ԫ�� (2 �� 1)
		2 ���Ҳ���� 1 ����С��Ԫ�� (1)
		6 ���Ҳ��� 1 ����С��Ԫ�� (1)
		1 ���Ҳ��� 0 ����С��Ԫ��*/
	void BSTInsert(BSTNode* node, BSTNode* insert_node, int& count_small);
	vector<int> countSmaller(vector<int>& nums);
};
