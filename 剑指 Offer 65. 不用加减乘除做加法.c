int add(int a, int b){
    // ����ͬΪ1��λ�ã�����һλ���н�λ
    while (a != 0) {
        // ��¼�������λ��λ��
        int temp = a ^ b;
        // �������ͬΪ��λֵ��λ��
        a = ((unsigned int) (a & b) << 1);
        b = temp;
    }
    return b;
}