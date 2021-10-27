#include "../Criteria/criteria.h"

//���ɸѡ���
void Criteria::printGoods(map<Goods, int> goods) {
	if (goods.size() == 0) {
		cout << "û������ɸѡ��������Ʒ��" << endl << endl;
		return;
	}

	cout << "����ɸѡ��������Ʒ���£�" << endl;
	for (map<Goods, int>::iterator iter = goods.begin(); iter != goods.end(); iter++) {
		cout << "��Ʒ���ƣ�" << iter->first.getName() << endl;
		cout << "��Ʒ�۸�" << iter->first.getPrice() << "Ԫ" << endl;
		//cout << "��Ʒ�����ڣ�" << iter->first.getOutDate() << endl;
		cout << "��Ʒ��棺" << iter->second << endl << endl;
	}
}

//&&����������������������������Ʒ
map<Goods, int> AndCriteria::filterGoods(map<Goods, int> goods){
	map<Goods, int> selectedGoods = criteria.filterGoods(goods);
	return otherCriteria.filterGoods(selectedGoods);
}

//�۸������������ָ���۸��������Ʒ
map<Goods, int> PriceCriteria::filterGoods(map<Goods, int> goods)
{
	map<Goods, int> selectedGoods;
	for (map<Goods, int>::iterator iter = goods.begin(); iter != goods.end(); iter++) {
		if (iter->first.getPrice() <= upperPrice && iter->first.getPrice() >= lowerPrice)
			selectedGoods.insert(pair<Goods, int>(iter->first, iter->second));
	}
	return selectedGoods;
}

//Ʒ�ƹ�����������ָ��Ʒ�Ƶ���Ʒ
map<Goods, int> BrandCriteria::filterGoods(map<Goods, int> goods)
{
	map<Goods, int> selectedGoods;
	for (map<Goods, int>::iterator iter = goods.begin(); iter != goods.end(); iter++) {
		if (iter->first.getShop()->getBrand() == standardBrand)
			selectedGoods.insert(pair<Goods,int>(iter->first,iter->second));
	}
	return selectedGoods;
}