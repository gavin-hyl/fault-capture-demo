std_msgs/Header header

uint8 severity_level

# Severity Level Enum
uint8 UNKNOWN = 0       # Severity unknown
uint8 INFO = 1          # Informational message
uint8 WARNING = 2       # Warning condition
uint8 ERROR = 3         # Error condition
uint8 FATAL = 4         # Fatal error condition

string warning_id       # Unique identifier for the fault
string description      # Brief description of the fault
string affected_node      # Name of the node affected by the fault

string error_code       # Error code associated with the fault (optional)
string[] possible_causes        # List of possible causes (optional)
string[] recommended_actions    # List of recommended actions (optional)