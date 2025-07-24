def count_subarrays_divisible_by_3(a):
    n = len(a)
    
    # Tạo prefix sums để tính số dư
    prefix_mod = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_mod[i] = (prefix_mod[i - 1] + a[i - 1]) % 3
    
    # Đếm số lần xuất hiện của mỗi số dư
    count_mod = [0] * 3
    count_mod[0] = 1  # Số dư 0 xuất hiện một lần (cho trường hợp ban đầu)
    total_count = 0
    
    for i in range(1, n + 1):
        total_count += count_mod[prefix_mod[i]]
        count_mod[prefix_mod[i]] += 1
    
    return total_count

# Ví dụ sử dụng
a = [5,23,2021]
print(count_subarrays_divisible_by_3(a))  