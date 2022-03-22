package enum_type

type EnvEnum int

const (
	Pro EnvEnum = iota + 1
	Pre
	DevAndTest
)

func NewEnvEnum(code int) *EnvEnum {
	result := new(EnvEnum)
	switch code {
	case 1:
		*result = Pro
	case 2:
		*result = Pre
	case 3:
		*result = DevAndTest
	case 0:
	default:
	}
	return result
}

func (envEnum EnvEnum) String() string {
	switch envEnum {
	case Pro:
		return "product"
	case Pre:
		return "pre"
	case DevAndTest:
		return "dev and test"
	case 0:
		return "not init"
	default:
		return "unknown"
	}
}
