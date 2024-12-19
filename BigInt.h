#ifndef BIGINT_CPP_CPP_
#define BIGINT_CPP_CPP_

#ifndef BIGINT_H_
#define BIGINT_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UnsignedBigInt {
public:
	typedef unsigned int value_type;
	typedef vector<value_type>::size_type size_type;
	typedef unsigned long long maxinteger_type;
	typedef int mode_type;
	enum strict_mode : mode_type {
		UnsignedBigIntUnUseStrict,
		UnsignedBigIntUseStrict
	};
	static const mode_type default_strict_mode =
	strict_mode::UnsignedBigIntUseStrict;
	
private:
	vector<value_type> val;
	mode_type isstrict;
private:
public:
	UnsignedBigInt();
	UnsignedBigInt(string& s, mode_type _strict = default_strict_mode);
	UnsignedBigInt(string&& s, mode_type _strict = default_strict_mode);
	UnsignedBigInt(const maxinteger_type _val,
		mode_type _strict = default_strict_mode);
	UnsignedBigInt(const vector<value_type>& val,
		mode_type _strict = default_strict_mode);
	UnsignedBigInt(const vector<value_type>&& val,
		mode_type _strict = default_strict_mode);
	~UnsignedBigInt() = default;

	inline explicit operator bool() const { return !val.empty(); }
	explicit operator string() const;
	explicit operator maxinteger_type() const;

	const UnsignedBigInt factorial() const;
	const maxinteger_type
	value() const;
	void set_strict(strict_mode _strict);
	strict_mode using_strict() const;
	inline const size_type back() const{return val.back();}
	
	const UnsignedBigInt operator+(const UnsignedBigInt&) const;
	const UnsignedBigInt operator+(const UnsignedBigInt&&) const;
	const UnsignedBigInt operator-(const UnsignedBigInt&) const;
	const UnsignedBigInt operator-(const UnsignedBigInt&&) const;
	const UnsignedBigInt operator*(const UnsignedBigInt&) const;
	const UnsignedBigInt operator*(const UnsignedBigInt&&) const;
	const UnsignedBigInt operator/(const UnsignedBigInt&) const;
	const UnsignedBigInt operator/(const UnsignedBigInt&&) const;
	const UnsignedBigInt operator%(const UnsignedBigInt&) const;
	const UnsignedBigInt operator%(const UnsignedBigInt&&) const;
	const UnsignedBigInt operator^(const maxinteger_type&)
	const;
	const UnsignedBigInt operator^(const maxinteger_type&&)
	const;
	inline const UnsignedBigInt operator+=(const UnsignedBigInt& a) {
		return ((*this) = (*this) + a);
	}
	
	inline const UnsignedBigInt operator+=(const UnsignedBigInt&& a) {
		return ((*this) = (*this) + a);
	}
	
	inline const UnsignedBigInt operator-=(const UnsignedBigInt& a) {
		return ((*this) = (*this) - a);
	}
	
	inline const UnsignedBigInt operator-=(const UnsignedBigInt&& a) {
		return ((*this) = (*this) - a);
	}
	
	inline const UnsignedBigInt operator*=(const UnsignedBigInt& a) {
		return ((*this) = (*this) * a);
	}
	
	inline const UnsignedBigInt operator*=(const UnsignedBigInt&& a) {
		return ((*this) = (*this) * a);
	}
	
	inline const UnsignedBigInt operator/=(const UnsignedBigInt& a) {
		return ((*this) = (*this) / a);
	}
	
	inline const UnsignedBigInt operator/=(const UnsignedBigInt&& a) {
		return ((*this) = (*this) / a);
	}
	
	inline const UnsignedBigInt operator%=(const UnsignedBigInt& a) {
		return ((*this) = (*this) % a);
	}
	
	inline const UnsignedBigInt operator%=(const UnsignedBigInt&& a) {
		return ((*this) = (*this) % a);
	}
	
	inline const UnsignedBigInt operator^=(const maxinteger_type& a) {
		return ((*this) = (*this) ^ a);
	}
	
	inline const UnsignedBigInt operator^=(const maxinteger_type&& a) {
		return ((*this) = (*this) ^ a);
	}
	
	inline const UnsignedBigInt operator++() { return ((*this) += 1U); }
	
	inline const UnsignedBigInt operator++(int) {
		auto res = (*this);
		++(*this);
		return res;
	}
	
	bool operator<(const UnsignedBigInt&) const;
	bool operator<=(const UnsignedBigInt&) const;
	
	inline bool operator>(const UnsignedBigInt& a) const {
		return !((*this) <= a);
	}
	
	inline bool operator>=(const UnsignedBigInt& a) const {
		return !((*this) < a);
	}
	
	bool operator==(const UnsignedBigInt&) const;
	
	inline bool operator!=(const UnsignedBigInt& a) const {
		return !((*this) == a);
	}
};

inline ostream& operator<<(ostream& os, const UnsignedBigInt& a) {
	os << string(a);
	return os;
}

inline ostream& operator<<(ostream& os, const UnsignedBigInt&& a) {
	os << string(a);
	return os;
}

istream& operator>>(istream& is, UnsignedBigInt& a);
istream& operator>>(istream& is, UnsignedBigInt&& a);
const UnsignedBigInt qpow(const UnsignedBigInt& a, const UnsignedBigInt& b,
		const UnsignedBigInt& p);
class BigInt {
public:
	typedef UnsignedBigInt::value_type value_type;
	typedef UnsignedBigInt::size_type size_type;
	typedef make_signed<UnsignedBigInt::maxinteger_type>::type maxinteger_type;
	typedef UnsignedBigInt::strict_mode strict_mode;
	typedef UnsignedBigInt::mode_type mode_type;
	
private:
	UnsignedBigInt val;
	bool sign;
private:
	inline void turn_sign() {
		if (val == 0)
			sign = false;
	}
	
public:
	BigInt();
	BigInt(string& s, mode_type _strict = UnsignedBigInt::default_strict_mode);
	BigInt(string&& s, mode_type _strict = UnsignedBigInt::default_strict_mode);
	BigInt(maxinteger_type _val,
		mode_type _strict = UnsignedBigInt::default_strict_mode);
	BigInt(const UnsignedBigInt&);
	BigInt(UnsignedBigInt&&) noexcept;
	~BigInt() {}
	
	inline explicit operator bool() const { return bool(val); }
	explicit operator string() const;
	explicit operator UnsignedBigInt() const;
	explicit operator maxinteger_type() const;
	
	bool isnegative() const;              //???????
	const BigInt factorial() const;       //???????
	void set_strict(strict_mode _strict); //??????
	strict_mode using_strict() const;     //????
	inline const size_type back() const{return val.back();}
	
	const BigInt operator-() const;
	const BigInt operator+(const BigInt&) const;
	const BigInt operator+(const BigInt&&) const;
	const BigInt operator-(const BigInt&) const;
	const BigInt operator-(const BigInt&&) const;
	const BigInt operator*(const BigInt&) const;
	const BigInt operator*(const BigInt&&) const;
	const BigInt operator/(const BigInt&) const;
	const BigInt operator/(const BigInt&&) const;
	const BigInt operator%(const BigInt&) const;
	const BigInt operator%(const BigInt&&) const;
	const BigInt operator^(const maxinteger_type&) const;
	const BigInt operator^(const maxinteger_type&&) const;

	inline const BigInt operator+=(const BigInt& a) {
		return ((*this) = (*this) + a);
	}
	
	inline const BigInt operator+=(const BigInt&& a) {
		return ((*this) = (*this) + a);
	}
	
	inline const BigInt operator-=(const BigInt& a) {
		return ((*this) = (*this) - a);
	}
	
	inline const BigInt operator-=(const BigInt&& a) {
		return ((*this) = (*this) - a);
	}
	
	inline const BigInt operator*=(const BigInt& a) {
		return ((*this) = (*this) * a);
	}
	
	inline const BigInt operator*=(const BigInt&& a) {
		return ((*this) = (*this) * a);
	}
	
	inline const BigInt operator/=(const BigInt& a) {
		return ((*this) = (*this) / a);
	}
	
	inline const BigInt operator/=(const BigInt&& a) {
		return ((*this) = (*this) / a);
	}
	
	inline const BigInt operator%=(const BigInt& a) {
		return ((*this) = (*this) % a);
	}
	
	inline const BigInt operator%=(const BigInt&& a) {
		return ((*this) = (*this) % a);
	}
	
	inline const BigInt operator^=(const maxinteger_type& a) {
		return ((*this) = (*this) ^ a);
	}
	
	inline const BigInt operator^=(const maxinteger_type&& a) {
		return ((*this) = (*this) ^ a);
	}
	
	inline const BigInt operator++() { return ((*this) += 1U); }
	inline const BigInt operator++(int) {
		auto res = (*this);
		++(*this);
		return res;
	}
	
	bool operator<(const BigInt&) const;
	bool operator<(const BigInt&&) const;
	bool operator<=(const BigInt&) const;
	bool operator<=(const BigInt&&) const;
	bool operator==(const BigInt&) const;
	bool operator==(const BigInt&&) const;
	inline bool operator>(const BigInt& a) const { return !((*this) <= a); }
	inline bool operator>(const BigInt&& a) const { return !((*this) <= a); }
	inline bool operator>=(const BigInt& a) const { return !((*this) < a); }
	inline bool operator>=(const BigInt&& a) const { return !((*this) < a); }
	inline bool operator!=(const BigInt& a) const { return !((*this) == a); }
	inline bool operator!=(const BigInt&& a) const { return !((*this) == a); }
};

inline ostream& operator<<(ostream& os, const BigInt& a) {
	os << string(a);
	return os;
}

inline ostream& operator<<(ostream& os, const BigInt&& a) {
	os << string(a);
	return os;
}

istream& operator>>(istream& is, BigInt& a);
istream& operator>>(istream& is, BigInt&& a);
const BigInt qpow(const BigInt& a, const BigInt& b, const BigInt& p);

#endif
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <exception>
#include <type_traits>
#include <vector>

UnsignedBigInt::UnsignedBigInt()
: isstrict(UnsignedBigInt::default_strict_mode) {
	val.push_back(0);
}

UnsignedBigInt::UnsignedBigInt(string& s, mode_type _strict)
: isstrict(_strict) {
	string::size_type len = s.length(), i = 0;
	while (i < len && s[i] == '0')
		++i;
	if (i == len) {
		val.push_back(0);
		return;
	}
	for (; i < len; i++) {
		if (isdigit(s[i]))
			val.push_back(s[i] - '0');
		else {
			if (isstrict) {
				val = vector<value_type>();
				cerr << __func__
				<< ":find a char "
				"not number!\n";
				throw exception();
				return;
			} else {
				return;
			}
		}
	}
}

UnsignedBigInt::UnsignedBigInt(string&& s, mode_type _strict)
: isstrict(_strict) {
	string::size_type len = s.length(), i = 0;
	while (i < len && s[i] == '0')
		++i;
	if (i == len) {
		val.push_back(0);
		return;
	}
	for (; i < len; i++) {
		if (isdigit(s[i]))
			val.push_back(s[i] - '0');
		else {
			if (isstrict) {
				val = vector<value_type>();
				cerr << __func__
				<< ":find a char "
				"not number!\n";
				throw exception();
				return;
			} else {
				return;
			}
		}
	}
}

UnsignedBigInt::UnsignedBigInt(UnsignedBigInt::maxinteger_type _val,
	mode_type _strict)
: isstrict(_strict) {
	if (_val == 0) {
		val.push_back(0);
		return;
	}
	while (_val) {
		val.push_back(_val % 10);
		_val /= 10;
	}
	val = vector<value_type>(val.rbegin(), val.rend());
}

UnsignedBigInt::UnsignedBigInt(const vector<value_type>& _val,
	mode_type _strict)
: val(_val), isstrict(_strict) {}
UnsignedBigInt::UnsignedBigInt(const vector<value_type>&& _val,
	mode_type _strict)
: val(_val), isstrict(_strict) {}

UnsignedBigInt::operator string() const {
	string ans;
	for (size_type i = 0, len = val.size(); i < len; i++) {
		ans += char(val[i] + '0');
	}
	return ans;
}

UnsignedBigInt::operator UnsignedBigInt::maxinteger_type() const {
	maxinteger_type ans = 0;
	for (size_type i = 0, len = val.size(); i < len; i++) {
		ans *= 10;
		ans += val[i];
	}
	return ans;
}

const UnsignedBigInt UnsignedBigInt::factorial() const {
	UnsignedBigInt ans(1U, isstrict);
	for (UnsignedBigInt i = 2; i <= (*this); ++i) {
		ans *= i;
	}
	return ans;
}

const UnsignedBigInt::maxinteger_type UnsignedBigInt::value() const {
	UnsignedBigInt::maxinteger_type ans = 0;
	for (auto it = val.rbegin(); it != val.rend(); ++it) {
		ans = ans * 10 + *it;
	}
	return ans;
}

void UnsignedBigInt::set_strict(strict_mode _strict) { isstrict = _strict; }
UnsignedBigInt::strict_mode UnsignedBigInt::using_strict() const {
	return static_cast<UnsignedBigInt::strict_mode>(isstrict);
}

const UnsignedBigInt UnsignedBigInt::operator+(const UnsignedBigInt& a) const {
	if ((*this) > a)
		return a + (*this);
	UnsignedBigInt ans;
	size_type lena = val.size(), lenb = a.val.size(), x = 0; // lena<=lenb
	ans.val.pop_back();
	for (size_type i = 0; i < lenb; i++) {
		if (i >= lena)
			ans.val.push_back(a.val[lenb - i - 1] + x);
		else
			ans.val.push_back(val[lena - i - 1] + a.val[lenb - i - 1] + x);
		x = ans.val[i] / 10;
		ans.val[i] %= 10;
	}
	if (x) {
		ans.val.push_back(x);
	}
	while (ans.val.size() && ans.val.back() == 0) {
		ans.val.pop_back();
	}
	if (ans.val.empty()) {
		ans.val.push_back(0);
	}
	ans.val = vector<value_type>(ans.val.rbegin(), ans.val.rend());
	
	return ans;
}

const UnsignedBigInt UnsignedBigInt::operator+(const UnsignedBigInt&& a) const {
	if ((*this) > a)
		return a + (*this);
	UnsignedBigInt ans;
	size_type lena = val.size(), lenb = a.val.size(), x = 0; // lena<=lenb
	ans.val.pop_back();
	for (size_type i = 0; i < lenb; i++) {
		if (i >= lena)
			ans.val.push_back(a.val[lenb - i - 1] + x);
		else
			ans.val.push_back(val[lena - i - 1] + a.val[lenb - i - 1] + x);
		x = ans.val[i] / 10;
		ans.val[i] %= 10;
	}
	if (x) {
		ans.val.push_back(x);
	}
	while (ans.val.size() && ans.val.back() == 0) {
		ans.val.pop_back();
	}
	if (ans.val.empty()) {
		ans.val.push_back(0);
	}
	ans.val = vector<value_type>(ans.val.rbegin(), ans.val.rend());
	
	return ans;
}

const UnsignedBigInt UnsignedBigInt::operator-(const UnsignedBigInt& a) const {
	if ((*this) < a) {
		cerr << __func__ << ":(*this)<a not alivible!\n";
		throw exception();
		return UnsignedBigInt();
	}
	UnsignedBigInt ans;
	size_type lena = val.size(), lenb = a.val.size(), x = 0; // lena>=lenb
	for (int i = 0; i < lena; i++) {
		std::make_signed<value_type>::type tmp;
		if (i >= lenb)
			tmp = val[lena - i - 1] - x;
		else
			tmp = val[lena - i - 1] - a.val[lenb - i - 1] - x;
		if (tmp < 0) {
			x = 1;
			ans.val.push_back(static_cast<value_type>(tmp + 10));
		} else {
			x = 0;
			ans.val.push_back(static_cast<value_type>(tmp));
		}
	}
	while (ans.val.size() && ans.val.back() == 0) {
		ans.val.pop_back();
	}
	if (ans.val.empty()) {
		return 0U;
	} else {
		ans.val = vector<value_type>(ans.val.rbegin(), ans.val.rend() - 1);
		return ans;
	}
}

const UnsignedBigInt UnsignedBigInt::operator-(const UnsignedBigInt&& a) const {
	if ((*this) < a) {
		cerr << __func__ << ":(*this)<a not alivible!\n";
		throw exception();
		return UnsignedBigInt();
	}
	UnsignedBigInt ans;
	size_type lena = val.size(), lenb = a.val.size(), x = 0; // lena>=lenb
	for (int i = 0; i < lena; i++) {
		std::make_signed<value_type>::type tmp;
		if (i >= lenb)
			tmp = val[lena - i - 1] - x;
		else
			tmp = val[lena - i - 1] - a.val[lenb - i - 1] - x;
		if (tmp < 0) {
			x = 1;
			ans.val.push_back(static_cast<value_type>(tmp + 10));
		} else {
			x = 0;
			ans.val.push_back(static_cast<value_type>(tmp));
		}
	}
	while (ans.val.size() && ans.val.back() == 0) {
		ans.val.pop_back();
	}
	if (ans.val.empty()) {
		return 0U;
	} else {
		ans.val = vector<value_type>(ans.val.rbegin(), ans.val.rend() - 1);
		return ans;
	}
}

const UnsignedBigInt UnsignedBigInt::operator*(const UnsignedBigInt& a) const {
	UnsignedBigInt ans;
	size_type lena = val.size(), lenb = a.val.size(), x = 0;
	for (size_type i = 0, len = lena + lenb; i < len; i++) {
		ans.val.push_back(0U);
	}
	for (size_type i = 0; i < lena; i++) {
		x = 0;
		for (size_type j = 0; j < lenb; j++) {
			ans.val[i + j] += val[lena - i - 1] * a.val[lenb - j - 1] + x;
			x = ans.val[i + j] / 10;
			ans.val[i + j] %= 10;
		}
		for (size_type j = 0; x; j++) {
			if (ans.val.size() > i + lenb + j) {
				ans.val[i + j + lenb] += x % 10;
				x = ans.val[i + j + lenb] / 10;
				ans.val[i + j + lenb] %= 10;
			} else {
				while (x) {
					ans.val.push_back(x % 10);
					x /= 10;
				}
				break;
			}
		}
	}
	
	while (ans.val.size() && *(ans.val.end() - 1) == 0) {
		ans.val.pop_back();
	}
	if (ans.val.empty()) {
		ans.val.push_back(0);
	}
	ans.val = vector<value_type>(ans.val.rbegin(), ans.val.rend());
	return ans;
}

const UnsignedBigInt UnsignedBigInt::operator*(const UnsignedBigInt&& a) const {
	UnsignedBigInt ans;
	size_type lena = val.size(), lenb = a.val.size(), x = 0;
	for (size_type i = 0, len = lena + lenb; i < len; i++) {
		ans.val.push_back(0U);
	}
	for (size_type i = 0; i < lena; i++) {
		x = 0;
		for (size_type j = 0; j < lenb; j++) {
			ans.val[i + j] += val[lena - i - 1] * a.val[lenb - j - 1] + x;
			x = ans.val[i + j] / 10;
			ans.val[i + j] %= 10;
		}
		for (size_type j = 0; x; j++) {
			if (ans.val.size() > i + lenb + j) {
				ans.val[i + j + lenb] += x % 10;
				x = ans.val[i + j + lenb] / 10;
				ans.val[i + j + lenb] %= 10;
			} else {
				while (x) {
					ans.val.push_back(x % 10);
					x /= 10;
				}
				break;
			}
		}
	}
	
	while (ans.val.size() && *(ans.val.end() - 1) == 0) {
		ans.val.pop_back();
	}
	if (ans.val.empty()) {
		ans.val.push_back(0);
	}
	ans.val = vector<value_type>(ans.val.rbegin(), ans.val.rend());
	return ans;
}

const UnsignedBigInt UnsignedBigInt::operator/(const UnsignedBigInt& a) const {
	if (a == 0U) { //????0
		cerr << __func__ << ":Cannot with zero!\n";
		throw exception();
		return UnsignedBigInt();
	} else if (a == 1U) { //??1????
		return (*this);
	}
	UnsignedBigInt ans, t(*this), t2(a);
	ans.val.pop_back();
	while (t2 <= t) {
		t2.val.push_back(0);
	}
	while (t >= a) {
		t2.val.pop_back();
		ans.val.push_back(0);
		while (t >= t2) {
			t -= t2;
			++ans.val[ans.val.size() - 1];
		}
	}
	while (t2 > a) {
		ans.val.push_back(0);
		t2.val.pop_back();
	}
	if (ans.val.empty()) {
		ans.val.push_back(0);
	}
	return ans;
}

const UnsignedBigInt UnsignedBigInt::operator/(const UnsignedBigInt&& a) const {
	if (a == 0U) { //????0
		cerr << __func__ << ":Cannot with zero!\n";
		throw exception();
		return UnsignedBigInt();
	} else if (a == 1U) { //??1????
		return (*this);
	}
	UnsignedBigInt ans, t(*this), t2(a);
	ans.val.pop_back();
	while (t2 <= t) {
		t2.val.push_back(0);
	}
	while (t >= a) {
		t2.val.pop_back();
		ans.val.push_back(0);
		while (t >= t2) {
			t -= t2;
			++ans.val[ans.val.size() - 1];
		}
	}
	while (t2 > a) {
		ans.val.push_back(0);
		t2.val.pop_back();
	}
	if (ans.val.empty()) {
		ans.val.push_back(0);
	}
	return ans;
}

const UnsignedBigInt UnsignedBigInt::operator%(const UnsignedBigInt& a) const {
	if (a == 0U) { //???0??
		cerr << __func__ << ":Cannot with zero!\n";
		throw exception();
		return UnsignedBigInt();
	} else if (a == 1U) { //???%1??0
		return 0;
	}
	UnsignedBigInt t(*this), t2(a);
	while (t2 <= t) {
		t2.val.push_back(0);
	}
	while (t >= a) {
		t2.val.pop_back();
		while (t >= t2) {
			t -= t2;
		}
	}
	return t;
}

const UnsignedBigInt UnsignedBigInt::operator%(const UnsignedBigInt&& a) const {
	if (a == 0U) { //???0??
		cerr << __func__ << ":Cannot with zero!\n";
		throw exception();
		return UnsignedBigInt();
	} else if (a == 1U) { //???%1??0
		return 0;
	}
	UnsignedBigInt t(*this), t2(a);
	while (t2 <= t) {
		t2.val.push_back(0);
	}
	while (t >= a) {
		t2.val.pop_back();
		while (t >= t2) {
			t -= t2;
		}
	}
	return t;
}

const UnsignedBigInt
UnsignedBigInt::operator^(const UnsignedBigInt::maxinteger_type& a) const {
	if (a == 0U)
		return 1U;
	else if (a == 1U)
		return (*this);
	else {
		UnsignedBigInt::maxinteger_type cnt = a;
		UnsignedBigInt s((*this)), ans(1, isstrict);
		while (cnt) {
			if (cnt & 1) {
				ans *= s;
			}
			s *= s;
			cnt >>= 1;
		}
		return ans;
	}
}

const UnsignedBigInt
UnsignedBigInt::operator^(const UnsignedBigInt::maxinteger_type&& a) const {
	if (a == 0U)
		return 1U;
	else if (a == 1U)
		return (*this);
	else {
		UnsignedBigInt::maxinteger_type cnt = a;
		UnsignedBigInt s((*this)), ans(1, isstrict);
		while (cnt) {
			if (cnt & 1) {
				ans *= s;
			}
			s *= s;
			cnt >>= 1;
		}
		return ans;
	}
}

bool UnsignedBigInt::operator<(const UnsignedBigInt& a) const {
	size_type lena = val.size(), lenb = a.val.size();
	if (lena < lenb)
		return true;
	else if (lena > lenb)
		return false;
	else {
		for (size_type i = 0; i < lena; i++) {
			if (val[i] < a.val[i])
				return true;
			else if (val[i] > a.val[i])
				return false;
		}
		return false;
	}
}

bool UnsignedBigInt::operator<=(const UnsignedBigInt& a) const {
	size_type lena = val.size(), lenb = a.val.size();
	if (lena < lenb)
		return true;
	else if (lena > lenb)
		return false;
	else {
		for (size_type i = 0; i < lena; i++) {
			if (val[i] < a.val[i])
				return true;
			else if (val[i] > a.val[i])
				return false;
		}
		return true;
	}
}

bool UnsignedBigInt::operator==(const UnsignedBigInt& a) const {
	size_type lena = val.size(), lenb = a.val.size();
	if (lena != lenb)
		return false;
	else {
		for (size_type i = 0; i < lena; i++) {
			if (val[i] != a.val[i])
				return false;
		}
		return true;
	}
}

istream& operator>>(istream& is, UnsignedBigInt& a) {
	string tmp;
	is >> tmp;
	try {
		a = tmp;
	} catch (...) {
		cerr << __func__ << ":Something wrong!\n";
		is.exceptions(std::istream::failbit);
	}
	return is;
}

istream& operator>>(istream& is, UnsignedBigInt&& a) {
	string tmp;
	is >> tmp;
	try {
		a = tmp;
	} catch (...) {
		cerr << __func__ << ":Something wrong!\n";
		is.exceptions(std::istream::failbit);
	}
	return is;
}

const UnsignedBigInt qpow(const UnsignedBigInt& a, const UnsignedBigInt& b,
		const UnsignedBigInt& p) {
	UnsignedBigInt ans = 1, tmp = a, nowb = b;
	while (nowb) {
		if (nowb.back() % 2) {
			ans *= tmp;
			ans %= p;
		}
		tmp *= tmp;
		nowb /= 2;
	}
	return ans;
}

BigInt::BigInt() : sign(false) {}
BigInt::BigInt(string& s, mode_type _strict) : sign(false) {
	val.set_strict(static_cast<strict_mode>(_strict));
	if (s[0] == '-') { //??
		sign = true;
		s.erase(s.begin());
	}
	val = s;
}

BigInt::BigInt(string&& s, mode_type _strict) : sign(false) {
	val.set_strict(static_cast<strict_mode>(_strict));
	if (s[0] == '-') { //??
		sign = true;
		s.erase(s.begin());
	}
	val = s;
}

BigInt::BigInt(BigInt::maxinteger_type _val, mode_type _strict) {
	if (_val >= 0) {
		sign = false;
		val = _val;
	} else {
		sign = true;
		val = -_val;
	}
	val.set_strict(static_cast<strict_mode>(_strict));
}
BigInt::BigInt(const UnsignedBigInt& _val) : val(_val), sign(false) {}
BigInt::BigInt(UnsignedBigInt&& _val) noexcept : val(_val), sign(false) {}
BigInt::operator string() const { return (sign ? "-" : "") + string(val); }
BigInt::operator UnsignedBigInt() const {
	if (sign) {
		cerr << __func__
		<< ":Cannot give class "
		"UnsignedBigInt a negative number!\n";
		throw exception();
		return UnsignedBigInt();
	}
	return val;
}

BigInt::operator BigInt::maxinteger_type() const {
	return maxinteger_type(UnsignedBigInt::maxinteger_type(val)) *
	(sign == false ? 1 : -1);
}

bool BigInt::isnegative() const { return !sign; }
const BigInt BigInt::factorial() const {
	if (sign) {
		cerr << __func__
		<< ":The factorial of a "
		"negative integer is undefined!\n";
		throw exception();
		return 0LL;
	}
	return val.factorial();
}

void BigInt::set_strict(strict_mode _strict) { val.set_strict(_strict); }
BigInt::strict_mode BigInt::using_strict() const { return val.using_strict(); }

const BigInt BigInt::operator-() const {
	BigInt ans;
	ans.sign = !sign;
	ans.val = val;
	return ans;
}

const BigInt BigInt::operator+(const BigInt& a) const {
	BigInt ans;
	switch ((sign << 1) | a.sign) {
		case 0: //????,?????
		ans = (val + a.val);
		break;
		case 1: //?????,a???,???(*this)-a.val
		ans = (val - a.val);
		break;
		case 2: //?????,a???,???a-(*this).val
		ans = (a.val - val);
		break;
		case 3: //????,????????
		ans = -BigInt((val + a.val));
		break;
	}
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator+(const BigInt&& a) const {
	BigInt ans;
	switch ((sign << 1) | a.sign) {
		case 0: //????,?????
		ans = (val + a.val);
		break;
		case 1: //?????,a???,???(*this)-a.val
		ans = (val - a.val);
		break;
		case 2: //?????,a???,???a-(*this).val
		ans = (a.val - val);
		break;
		case 3: //????,????????
		ans = -BigInt((val + a.val));
		break;
	}
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator-(const BigInt& a) const {
	BigInt ans;
	switch ((sign << 1) | a.sign) {
		case 0: //????,?????,???????0???
		if (val < a.val) {
			ans = -BigInt(a.val - val);
		} else {
			ans = (val - a.val);
		}
		break;
		case 1: //?????,a???,???(*this)+a.val
		ans = (val + a.val);
		break;
		case 2: //?????,a???,???-(a.val+(*this))
		ans = -BigInt(a.val + val);
		break;
		case 3: //????,???(a.val-(*this)),?????????0???
		if (val <= a.val) {
			ans = (a.val - val);
		} else {
			ans = -BigInt(val - a.val);
		}
		break;
	}
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator-(const BigInt&& a) const {
	BigInt ans;
	switch ((sign << 1) | a.sign) {
		case 0: //????,?????,???????0???
		if (val < a.val) {
			ans = -BigInt(a.val - val);
		} else {
			ans = (val - a.val);
		}
		break;
		case 1: //?????,a???,???(*this)+a.val
		ans = (val + a.val);
		break;
		case 2: //?????,a???,???-(a.val+(*this))
		ans = -BigInt(a.val + val);
		break;
		case 3: //????,???(a.val-(*this)),?????????0???
		if (val <= a.val) {
			ans = (a.val - val);
		} else {
			ans = -BigInt(val - a.val);
		}
		break;
	}
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator*(const BigInt& a) const {
	BigInt ans;
	if (a.sign != sign)
		ans = -BigInt(
			val * a.val); //????,????????,???????????
	else
		ans =
		val * a.val; //????,??????,??????,???????
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator*(const BigInt&& a) const {
	BigInt ans;
	if (a.sign != sign)
		ans = -BigInt(
			val * a.val); //????,????????,???????????
	else
		ans =
		val * a.val; //????,??????,??????,???????
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator/(const BigInt& a) const {
	BigInt ans;
	if (a.sign != sign)
		ans = -BigInt(
			val / a.val); //????,????????,???????????
	else
		ans = val / a.val; //????,???????,????????
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator/(const BigInt&& a) const {
	BigInt ans;
	if (a.sign != sign)
		ans = -BigInt(
			val / a.val); //????,????????,???????????
	else
		ans = val / a.val; //????,???????,????????
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator%(const BigInt& a) const {
	BigInt ans;
	switch ((sign << 1) | a.sign) {
		case 0: //????
		ans = val % a.val;
		break;
		case 1: //?????,a???
		ans = -BigInt(a.val - val % a.val);
		break;
		case 2: //?????,a???
		ans = a.val - val % a.val;
		break;
		case 3: //????
		ans = -BigInt(val % a.val);
		break;
	}
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator%(const BigInt&& a) const {
	BigInt ans;
	switch ((sign << 1) | a.sign) {
		case 0: //????
		ans = val % a.val;
		break;
		case 1: //?????,a???
		ans = -BigInt(a.val - val % a.val);
		break;
		case 2: //?????,a???
		ans = a.val - val % a.val;
		break;
		case 3: //????
		ans = -BigInt(val % a.val);
		break;
	}
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator^(const BigInt::maxinteger_type& a) const {
	BigInt ans;
	if (a < 0) {           //??a???
		return 0;          //??????0??????1,??
	} else if (a & sign) { //??a?????sign?true(??)
		ans = -BigInt(val ^ a);
	} else { //??????????,????????????(???,????)
		ans = (val ^ a);
	}
	ans.turn_sign();
	return ans;
}

const BigInt BigInt::operator^(const BigInt::maxinteger_type&& a) const {
	BigInt ans;
	if (a < 0) {           //??a???
		return 0;          //??????0??????1,??
	} else if (a & sign) { //??a?????sign?true(??)
		ans = -BigInt(val ^ a);
	} else { //??????????,????????????(???,????)
		ans = (val ^ a);
	}
	ans.turn_sign();
	return ans;
}

bool BigInt::operator<(const BigInt& a) const {
	if (sign < a.sign)
		return false; //???a?,(*this)>a
	else if (sign > a.sign)
		return true; //???a?,(*this)<a
	else if (sign) { //?????:????????
		return val > a.val;
	} else { //?????:????????
		return val < a.val;
	}
}

bool BigInt::operator<(const BigInt&& a) const {
	if (sign < a.sign)
		return false; //???a?,(*this)>a
	else if (sign > a.sign)
		return true; //???a?,(*this)<a
	else if (sign) { //?????:????????
		return val > a.val;
	} else { //?????:????????
		return val < a.val;
	}
}

bool BigInt::operator<=(const BigInt& a) const {
	if (sign < a.sign)
		return false; //???a?,(*this)>a
	else if (sign > a.sign)
		return true; //???a?,(*this)<a
	else if (sign) { //?????:????????
		return val >= a.val;
	} else { //?????:????????
		return val <= a.val;
	}
}

bool BigInt::operator<=(const BigInt&& a) const {
	if (sign < a.sign)
		return false; //???a?,(*this)>a
	else if (sign > a.sign)
		return true; //???a?,(*this)<a
	else if (sign) { //?????:????????
		return val >= a.val;
	} else { //?????:????????
		return val <= a.val;
	}
}

bool BigInt::operator==(const BigInt& a) const {
	if (val == 0 && a.val == 0)
		return true;
	if (sign != a.sign)
		return false; //?????,??????
	else
		return val == a.val; //???????????
}

bool BigInt::operator==(const BigInt&& a) const {
	if (sign != a.sign)
		return false; //?????,??????
	else
		return val == a.val; //???????????
}

istream& operator>>(istream& is, BigInt& a) {
	string tmp;
	is >> tmp;
	try {
		a = tmp;
	} catch (...) {
		cerr << __func__ << ":Something wrong!\n";
		is.exceptions(std::istream::failbit);
	}
	return is;
}

istream& operator>>(istream& is, BigInt&& a) {
	string tmp;
	is >> tmp;
	try {
		a = tmp;
	} catch (...) {
		cerr << __func__
		<< ":Something "
		"wrong!\n";
		is.exceptions(std::istream::failbit);
	}
	return is;
}

const BigInt qpow(const BigInt& a, const BigInt& b, const BigInt& p) {
	BigInt ans = 1, tmp = a, nowb = b;
	while (nowb > 0) {
		if (nowb.back() % 2) {
			ans *= tmp;
			ans %= p;
		}
		tmp *= tmp;
		nowb /= 2;
	}
	return ans;
}
#endif
