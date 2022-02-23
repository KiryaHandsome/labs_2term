bool check_equals(Expression const* left, Expression const* right)
{
    int* vptr1 = (int*)left;
    int* vptr2 = (int*)right;
    if (*vptr1 == *vptr2) return true;
    return false;
}
