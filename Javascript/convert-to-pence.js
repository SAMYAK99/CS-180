// Convert pounds to pence

const convertToPence = (valueInPounds) => {
  try {
    const currencyArray = valueInPounds.toString().split('.').filter(x => x.length > 0)
    const pounds = currencyArray[0]
    const pence = (currencyArray[1] ?? '00').padEnd(2, '0')
    const value = Number(pounds + pence)
    return Number.isInteger(value) ? value : undefined
  } catch {
    return undefined
  }
}
