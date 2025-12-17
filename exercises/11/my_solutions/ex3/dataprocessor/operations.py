
def process_data(df, col1, col2, res_col):
    df[res_col] = df[col1] + df[col2]
    return df


def additional_operation(df, col1, col2, add_col1, add_col2):
    df[add_col1] = df[col1] * df[col2]
    df[add_col2] = df[col1] / df[col2]
    return df


