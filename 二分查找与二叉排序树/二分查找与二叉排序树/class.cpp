#include<iostream>
#include<vector>
#include "class.h"
#include<string>
using namespace std;


//1.����ѭ��ʵ�ֶ��ֲ���
bool solution::binary_search1(vector<int>& sort_array, int target) {
	int begin = 0;
	int end = sort_array.size() - 1;
	int mid = (begin + end) / 2;

	while (begin <= end) {
		if (target == sort_array[mid]) {
			return true;
		}
		else if (target < sort_array[mid]) {
			end = mid - 1;
			mid = (begin + end) / 2;
		}
		else if (target > sort_array[mid]) {
			begin = mid + 1;
			mid = (begin + end) / 2;
		}
	}
	return false;
}

//2.���õݹ�ʵ�ֶ��ֲ���
bool solution::binary_search2(vector<int>& sort_array, int begin, int end, int target) {
	if (begin > end) {
		return false;
	}
	int mid = (begin + end) / 2;
	if (target == sort_array[mid]) {
		return true;
	}
	else if (target < sort_array[mid]) {
		binary_search2(sort_array, begin, mid - 1, target);
	}
	else if (target > sort_array[mid]) {
		binary_search2(sort_array, mid + 1, end, target);
	}
}

/*3.����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
		���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
		����Լ������������ظ�Ԫ�ء�leetcode(35)*/
int solution::searchInsert(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;
	int index = -1;

	while (index == -1) {
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			index = mid;
		}
		else if (target < nums[mid]) {
			if (mid == 0 || target > nums[mid - 1]) {
				index = mid;
			}
			end = mid - 1;
		}
		else if (target > nums[mid]) {
			if (mid == nums.size() - 1 || target < nums[mid + 1]) {
				index = mid + 1;
			}
			begin = mid + 1;
		}
	}
	return index;
}

/*4.����һ�������������е��������� nums����һ��Ŀ��ֵ target��
		�ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
		��������в�����Ŀ��ֵ target������ [-1, -1]��*/

int solution::left_bound(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;

	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			if (mid == 0 || target > nums[mid - 1]) {
				return mid;
			}
			end = mid - 1;
		}
		else if (target < nums[mid]) {
			end = mid - 1;
		}
		else if (target > nums[mid]) {
			begin = mid + 1;
		}
	}
	return -1;

}
int solution::right_bound(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;

	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			if (mid == nums.size() - 1 || target < nums[mid + 1]) {
				return mid;
			}
			begin = mid + 1;
		}
		else if (target < nums[mid]) {
			end = mid - 1;
		}
		else if (target > nums[mid]) {
			begin = mid + 1;
		}
	}
	return -1;

}
vector<int> solution::searchRange(vector<int>& nums, int target) {
	int left = left_bound(nums, target);
	int right = right_bound(nums, target);

	vector<int> result;
	result.push_back(left);
	result.push_back(right);
	return result;
}


//5.��ת�������
int solution::search(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;

	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			return mid;
		}
		else if (target < nums[mid]) {
			if (nums[begin] < nums[mid]) {
				if (target >= nums[begin]) {
					end = mid - 1;
				}
				else {
					begin = mid + 1;
				}
			}
			else if (nums[begin] > nums[mid]) {
				end = mid - 1;
			}
			else if (nums[begin] == nums[mid]) {
				begin = mid + 1;
			}
		}
		else if (target > nums[mid]) {
			if (nums[begin] < nums[mid]) {
				begin = mid + 1;
			}
			else if (nums[begin] > nums[mid]) {
				if (target >= nums[begin]) {
					end = mid - 1;
				}
				else {
					begin = mid + 1;
				}
			}
			else if (nums[begin] == nums[mid]) {
				begin = mid + 1;
			}
		}
	}
	return -1;
}


/*6.����������Ĳ���ʵ��*/
void solution::BST_insert(TreeNode* node, TreeNode* insert_node) {
	if (insert_node->val < node->val) {
		if (node->left) {
			BST_insert(node->left, insert_node);
		}
		else {
			node->left = insert_node;
		}
	}
	else {
		if (node->right) {
			BST_insert(node->right, insert_node);
		}
		else {
			node->right = insert_node;
		}
	}
}

/*7.����������������*/
bool solution::BST_search(TreeNode* node, int value) {
	if (value == node->val) {
		return true;
	}
	else if (value < node->val) {
		if (node->left) {
			BST_search(node->left, value);
		}
		else {
			return false;
		}
	}
	else if (value > node->val) {
		if (node->right) {
			BST_search(node->right, value);
		}
		else {
			return false;
		}
	}
}

/*8.���ַ�������ת��Ϊ���֡����磺str:"12345",int:12345*/
int solution::pow_int(int a, int b) {
	int sum = 1;
	for (int i = 0; i < b; i++) {
		sum = sum*a;
	}
	return sum;
}
int solution::str_to_int(string& str) {
	int length = str.size();
	vector<int> array;
	int sum = 0;
	for (int i = 0; i < length; i++) {
		array.push_back(str[i]-'0');
	}
	for (int i = length - 1,j=0; i >= 0; i--,j++) {
		sum = sum + array[i] * pow_int(10,j);
	}
	return sum;
}

/*9 ���л��ͷ����л�����������*/
	/*9.1������ת��Ϊ�ַ���#����ʽ�����磺int��1234 -> string:"1234#"*/
void solution::change_int_to_string(int val, string& str_val) {
	string tmp;
	while (val) {
		tmp += val % 10 + '0';
		val = val / 10;
	}
	for (int i = tmp.length()- 1; i >= 0; i--) {
		str_val += tmp[i];
	}
	str_val += '#';
}
	/*9.2 ���������������ǰ������ķ�ʽ��ת��Ϊ�ַ���������֮��ʹ��#����*/
void solution::BST_preorder(TreeNode* node, string& data) {
	if (!node) {
		return;
	}
	string str_val;
	change_int_to_string(node->val, str_val);
	data += str_val;
	BST_preorder(node->left, data);
	BST_preorder(node->right, data);
}

// Encodes a tree to a single string.
string solution::serialize(TreeNode* root) {
	string data;
	BST_preorder(root, data);
	return data;
}

// Decodes your encoded data to tree.
TreeNode* solution::deserialize(string data) {
	int val = 0;
	vector<TreeNode*> node_vec;

	if (data.length() == 0) {
		return NULL;
	}

	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '#') {
			node_vec.push_back(new TreeNode(val));
			val = 0;
		}
		else {
			val = val * 10 + (data[i] - '0');
		}
	}

	for (int i = 1; i < node_vec.size(); i++) {
		BST_insert(node_vec[0], node_vec[i]);
	}
	return node_vec[0];
}



/*10.����һ���������� nums����Ҫ�󷵻�һ�������� counts��
     ���� counts �и����ʣ� counts[i] ��ֵ��  nums[i] �Ҳ�С�� nums[i] ��Ԫ�ص�������*/
void solution::BSTInsert(BSTNode* node, BSTNode* insert_node, int& count_small) {
	if (insert_node->val <= node->val) {
		node->count++;
		if (node->left) {
			BSTInsert(node->left, insert_node, count_small);
		}
		else {
			node->left = insert_node;
		}
	}
	else {
		count_small += node->count + 1;
		if (node->right) {
			BSTInsert(node->right, insert_node, count_small);
		}
		else {
			node->right = insert_node;
		}
	}
}

vector<int> solution::countSmaller(vector<int>& nums) {
	vector<int> result;
	vector<int> count;
	vector<BSTNode*> node_vec;

	for (int i = nums.size() - 1; i >= 0; i--) {
		node_vec.push_back(new BSTNode(nums[i]));
	}

	count.push_back(0);
	for (int i = 1; i < node_vec.size(); i++) {
		int count_small = 0;
		BSTInsert(node_vec[0], node_vec[i], count_small);
		count.push_back(count_small);
	}

	for (int i = node_vec.size() - 1; i >= 0; i--) {
		delete node_vec[i];
		result.push_back(count[i]);
	}
	return result;
}