#ifndef _SEARCH_H
#define _SEARCH_H


class search{
	public:
	search();	//�R���X�g���N�^
	~search();	//�f�X�g���N�^
	void SearchBall();
	void GetBall();
	void FireBall();
	void Fun(int mode);
	float Search_theta;
	float default_x;
	float default_y;
};



#endif //_SEARCH_H
