// O(n)
// Runtime Beats 100.00%

type ArrayStack struct {
	data []interface{}
	top  int
}

func (this *ArrayStack) IsEmpty() bool {
	if this.top < 0 {
		return true
	} else {
		return false
	}
}

func (this *ArrayStack) Push(v interface{}) {
	if this.top < 0 {
		this.top = 0
	} else {
		this.top++
	}

	if this.top > len(this.data)-1 {
		this.data = append(this.data, v)
	} else {
		this.data[this.top] = v
	}
}

func (this *ArrayStack) Pop() interface{} {
	if this.IsEmpty() {
		return nil
	}

	v := this.data[this.top]
	this.top--
	return v
}

func (this *ArrayStack) Top() interface{} {
	if this.IsEmpty() {
		return nil
	}
	return this.data[this.top]
}

func NewArrayStack(n int) *ArrayStack {
	return &ArrayStack{
		data: make([]interface{}, 0, n),
		top:  -1,
	}
}

func isLeftbracket(c byte) bool {
	switch c {
	case '{':
		return true
	case '[':
		return true
	case '(':
		return true
	default:
		return false
	}
	return false
}

func match(left byte, right byte) bool {
	switch left {
	case '{':
		return right == '}'
	case '[':
		return right == ']'
	case '(':
		return right == ')'
	default:
		return false
	}
	return false
}

func isValid(s string) bool {
	st := NewArrayStack(32)
	for _, ch := range []byte(s) {
		if isLeftbracket(ch) {
			st.Push(ch)
		} else {
			if st.IsEmpty() {
				return false
			} else {
				top := st.Top()
				if match(top.(byte), ch) {
					st.Pop()
				} else {
					return false
				}
			}
		}
	}
	return st.IsEmpty()
}