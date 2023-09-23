// Check i-th bit, set i-th bit and unset i-th bit of a number

vector<int> bitManipulation(int num, int i){
    // i-th bit of num
    int i_bit = ((num & (1 << (i-1) )) != 0 ? 1 : 0);
    int set_i_th_bit = (num | (1 << (i-1)));
    int unset_i_th_bit = num & (~(1 << (i-1)));
    return {i_bit, set_i_th_bit, unset_i_th_bit};
}