# SimpleBank

## Structure
Planning
- Create account
  - Name
  - Account Number
  - Balance
  - Overdraft limit
  - Available balance (includes overdraft, subtracts pending payments
  - Pending payments (vector)
- Withdraw
- Deposit
- Transfer
  - Allow for list of different accounts
  - Type in which accounts you want to transfer from/into
- Make payment
  - Second account to transfer from
  - Perhaps accept an Account number and an amount
  - Check to see if account has the available cash for payment
  - Return reject if false
- View details
  -- Display account details
