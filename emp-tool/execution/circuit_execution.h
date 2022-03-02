#ifndef EMP_CIRCUIT_EXECUTION_H__
#define EMP_CIRCUIT_EXECUTION_H__
#include "emp-tool/utils/block.h"
#include "emp-tool/utils/constants.h"

namespace emp {

/* Circuit Pipelining 
 * [REF] Implementation of "Faster Secure Two-Party Computation Using Garbled Circuit"
 * https://www.usenix.org/legacy/event/sec11/tech/full_papers/Huang.pdf
 */
class CircuitExecution { public:
#ifndef THREADING
	static CircuitExecution * circ_exec;
#else
	static __thread CircuitExecution * circ_exec;
#endif
	virtual void and_gate(void * out, const void * in1, const void * in2) = 0;
	virtual void xor_gate(void * out, const void * in1, const void * in2) = 0;
	virtual void not_gate(void * out, const void * in1) = 0;
	virtual void public_label(void * out, bool b) = 0;
	virtual uint64_t num_and() {
		return -1;
	}
	virtual ~CircuitExecution (){ }
};
enum RTCktOpt{on, off};
}
#endif